#ifndef __SORT_H__
#define __SORT_H__
#include <iostream>
#include <string>
#include <ofstream>
#include <fstream>
#include <map>
#define OUTSIZE sizeof(char) * 1024 * 1024 * 990    //990M
typedef unsigned int UINT;
struct Time{ 
    UINT:16 year;
    UINT:8 month;
    UINT:8 day;
    UINT:8 hour;
    UINT:8 minute;
    UINT:16 second;
    UINT us;
    operator < (Time& t)
    { 
        if(this->year < t.year) return true;
        if(this->month < t.month) return true;
        if(this->day < t.day) return true;
        if(this->hour < t.hour) return true;
        if(this->minute < t.minute) return true;
        if(this->second< t.second) return true;
        if(this->us < t.us) return true;
        return false;
    }
};
struct LogInfo{ 
    std::string line;
    ofstream logfd;
};
class Sort{
public:
    Sort(std::string conf) : size(0), outstr(nullptr){ 
        fstream fd(conf);
        std::string line;
        while(getline(fd, line))
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
