#pragma once
#ifndef __SORT_H__
#define __SORT_H__
#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
#define OUTSIZE sizeof(char) * 1024 * 1024 * 990    //990M
typedef unsigned int UINT;
struct Time {
	UINT year : 16;
	UINT month : 8;
	UINT day : 8;
	UINT hour : 8;
	UINT minute : 8;
	UINT second : 16;
	//UINT us;
	bool operator < (const Time t) const
	{
		if (this->year < t.year) return true;
		if (this->month < t.month) return true;
		if (this->day < t.day) return true;
		if (this->hour < t.hour) return true;
		if (this->minute < t.minute) return true;
		if (this->second< t.second) return true;
		//if (this->us < t.us) return true;
		return false;
	}
};
struct LogInfo {
	std::string line;
	fstream *logfd;
};
class Sort {
public:
	Sort(std::string conf) : size(0), outstr(nullptr) {
		fstream fd(conf);
		std::string line;
		while (getline(fd, line))
		{
			confs.push_back(line);
		}
		init();
	}
	
public:
	void init();
	bool gettime(std::string logline, Time &t);
	void sort();

public:
	std::map<Time, LogInfo *> sortInfo;
	std::vector<std::string> confs;
	std::string *outstr;
	unsigned long long size;
	std::string outfile;
};
#endif
