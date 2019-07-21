#include "Sort.h"
void Sort::init()
{ 
    for(auto f : confs){ 
        fstream fdtmp;
        std::string line;
        if(getline(fdtemp, line))
        {
            Time time;
            do{ 
                
            }while(!gettime(line, time))
            LogInfo* li = new LogInfo;
            li->line = line;
            li->logfd = fdtmp;
            sortInfo.insert(std::make_pair(time, li));
        }
    }
    outstr = new std::string(OUTSIZE);

}

bool Sort::gettime(std::string logline, Time& t)
{ 
    
}

void Sort::sort()
{ 
    while(0 != sortInfo.size())
    { 
        auto it = sortInfo.begin();
        *outstr += it->second->line;
        if(size + it->second->line.size() >= OUTSIZE)
        { 
            ofstream writefd;
            writefd.open(outfile, ios::app);
            writefd << *outstr << endl;
            writefd.close();
            *outstr.clear();
            size = 0;
        }
        size += it->second->line.size();
        it->second->line.clear();
        LogInfo* tmp = it->second;
        sortInfo.erase(it);
        std::string line;
        if(getline(tmp->logfd, line))
        { 
            Time tt;
            if(gettime(line, tt))
            { 
                sortInfo.insert(std::make_pair(tt, tmp));
            }
        }
    }
}
