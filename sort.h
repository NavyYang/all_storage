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
	UINT year;
	UINT month;
	UINT day;
	UINT hour;
	UINT minute;
	UINT second;
	Time ():year(0), month(0), day(0), hour(0), minute(0), second(0){}
	bool isValidTime() {
		if (!year || !month || !day) return false;
		return true;
	}
	//UINT us;
	//bool operator () (const Time& t1, const Time& t2) const
	//{
	//	if (t1.year < t2.year) return true;
	//	if (t1.month < t2.month) return true;
	//	if (t1.day < t2.day) return true;
	//	if (t1.hour < t2.hour) return true;
	//	if (t1.minute < t2.minute) return true;
	//	if (t1.second < t2.second) return true;
	//	//if (this->us < t.us) return true;
	//	return false;
	//}
};
class Compare {
public:
	bool operator()(const Time& lhs, const Time& rhs)const
	{
		if (lhs.year > rhs.year)
		{
			return false;
		}
		else if (lhs.year == rhs.year)
		{
			if (lhs.month > rhs.month)
			{
				return false;
			}
			else if (lhs.month == rhs.month)
			{
				if (lhs.day > rhs.day)
				{
					return false;
				}
				else if (lhs.day == rhs.day)
				{
					if (lhs.hour > rhs.hour)
					{
						return false;
					}
					else if (lhs.hour == rhs.hour)
					{
						if (lhs.minute > rhs.minute)
						{
							return false;
						}
						else if (lhs.minute == rhs.minute)
						{
							if (lhs.second > rhs.second)
							{
								return false;
							}
							else if (lhs.second == rhs.second)
							{
								return false;
							}
						}
					}
				}
			}
		}
		
		 
		 
		 
		//if (this->us < t.us) return true;
		return true;
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
		outfile = "C:\\Project\\all_storage\\build\\all_storage\\testcase\\total.txt";
		std::string line;
		while (getline(fd, line))
		{
			confs.push_back(line);
		}
		fd.close();
		init();
	}
	~Sort() {
		ofstream writefd;
		writefd.open(outfile, ios::app);
		writefd << outstr << endl;
		writefd.close();
		memset(outstr, OUTSIZE, '\0');
		size = 0;
		free(outstr);
		outstr = NULL;
		
	}
	
public:
	void init();
	bool gettime(std::string logline, Time &t);
	void sort();

public:
	std::map<Time, LogInfo *, Compare> sortInfo;
	std::vector<std::string> confs;
	char* outstr;
	unsigned long long size;
	std::string outfile;
};
#endif
