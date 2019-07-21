#!/usr/bin/python3
import datetime
import os
import subprocess
import json

unstableheadfile = {}
def writeUnstableHeadFiel(unstableheadfile):
    resultpath = os.path.abspath('.') +os.path.sep + 'unstable.json'
    fd = open(resultpath, 'w')
    fd.write(json.dumps(unstableheadfile, sort_keys=False, indent=4, separators=(',', ':'), encoding="utf-8", ensure_ascii=False))
    fd.close()
    
def readconf():
    resultpath = os.path.abspath('.') +os.path.sep + 'unstable.json'
    fd = open(resultpath, 'r')
    data = json.load(fd)
    fd.close()
    if data.has_key(''):
        path = data['']
    
if __name__ == "__main__":
    ExecCmd = []
    ExecCmd.append(r'git log --since=45.month --stat --pretty=format:"" -- Resources/TileMaps');
    
    
    workpath = r'C:\\Project\\github\\mota'
    resultpath = os.path.abspath('.') +os.path.sep + 'result.txt'
    print 'resultpath: ' + resultpath
    fd = open(resultpath, 'w')
    print 'ExecCmd: ' + ' '.join(ExecCmd)
    fd.write('Git commond : ' + ExecCmd[0] + '\n')
    fd.flush()
    print 'work path : ' + os.path.abspath('.')
    proc1 = subprocess.Popen(ExecCmd[0], cwd=workpath, shell=False, stdout=fd);
    fd.close()
    resultpath1 = os.path.abspath('.') +os.path.sep + 'result1.txt'
    print 'result1path: ' + resultpath1
    ExecCmd.append(r'findstr /c:".png" ' + resultpath + ' > ' + resultpath1 + ' 2>&1')
    print 'findstr commond : ' + ExecCmd[1]
    proc2 = os.system(ExecCmd[1])
    out = os.popen(r'findstr /c:\".png\" C:\\Project\\python_test\\result.txt > C:\\Project\\python_test\\result1.txt 2>&1')
    print 'work path : ' + os.path.abspath('.')
    
    unstableheadfile['unstableheadfile'] = []
    unstableheadfile['unstableheadfile'].append('file1.h')
    unstableheadfile['unstableheadfile'].append('file2.h')
    unstableheadfile['unstableheadfile'].append('file3.h')
    unstableheadfile['unstableheadfile'].append('file4.h')
    
    unstableheadfile['inde'] = {}
    unstableheadfile['indee'] = {}
    writeUnstableHeadFiel(unstableheadfile)
    