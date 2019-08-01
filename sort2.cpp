#include "stdafx.h"

#include "sort.h"
#include "Sort.h"
void Sort::init()
{
	for (auto f : confs) {
		fstream *fdtmp = new fstream();
		std::string line;
		fdtmp->open(f);
		if (!fdtmp->fail())
		{
			do {

			} while (!getline(*fdtmp, line));
			Time time;
			gettime(line, time);
			LogInfo* li = new LogInfo;
			li->line = line;
			li->logfd = fdtmp;
			sortInfo.insert(std::make_pair(time, li));
		}
	}
	outstr = (string *)malloc(OUTSIZE);

}

//year-month-day h:m:s us
bool Sort::gettime(std::string logline, Time& t)
{
	const char *dt = logline.c_str();
	int i = 0;
	int number = 0;
	char tmp[16] = {0 };
	char* p = tmp;
	int j = 0;
	while (dt[i] != '\0')
	{
		
		tmp[j] = dt[i];
		j++;
		if ('-' == dt[i])
		{
			tmp[j-1] = '\0';
			if (0 == number)
			{
				int n;
				n = atoi(tmp);
				t.year = n;
			}
			else if (1 == number) {
				int n;
				n = atoi(tmp);
				t.month = n;
			}
			number++;
			j = 0;
			memset(tmp, 0, sizeof(tmp));
		}
		else if (' ' == dt[i] && 2 == number)
		{
			tmp[j - 1] = '\0';
			int n;
			n = atoi(tmp);
			t.day = n;
			number++;
			j = 0;
			memset(tmp, 0, sizeof(tmp));
		}
		else if (':' == dt[i])
		{
			tmp[j - 1] = '\0';
			if (3 == number)
			{
				int n;
				n = atoi(tmp);
				t.hour = n;
			}
			else if (4 == number) {
				int n;
				n = atoi(tmp);
				t.minute = n;
			}
			number++;
			j = 0;
			memset(tmp, 0, sizeof(tmp));
		}
		else if (' ' == dt[i] && 5 == number)
		{
			tmp[j - 1] = '\0';
			int n;
			n = atoi(tmp);
			t.second = n;
			number++;
			j = 0;
			memset(tmp, 0, sizeof(tmp));
		}
		//else if (' ' == dt[i] && 7 == number)
		//{
		//	int n;
		//	_itoa(n, p, 10);
		//	t.us = n;
		//	number++;
		//	p = tmp;
		//	memset(tmp, 0, sizeof(tmp));
		//}
		if (6 == number) break;
		i++;
		
	}
	return true;
}

void Sort::sort()
{
	while (0 != sortInfo.size())
	{
		auto it = sortInfo.begin();
		*outstr += it->second->line;
		if (size + it->second->line.size() >= OUTSIZE)
		{
			ofstream writefd;
			writefd.open(outfile, ios::app);
			writefd << *outstr << endl;
			writefd.close();
			(*outstr).clear();
			size = 0;
		}
		size += it->second->line.size();
		it->second->line.clear();
		LogInfo* tmp = it->second;
		sortInfo.erase(it);
		std::string line;
		if (getline(*tmp->logfd, line))
		{
			Time tt;
			if (gettime(line, tt))
			{
				sortInfo.insert(std::make_pair(tt, tmp));
			}
		}
		else {
			tmp->logfd->close();
			delete tmp->logfd;
		}
	}
}