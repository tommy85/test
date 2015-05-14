#!/usr/local/bin/python                  #  1
                                         #  2
#cat numberlines.py|python numberlines.py #  3
#or usr 'python numberlines.py numberlines.py' #  4
                                         #  2 #  5
import fileinput                         #  3 #  6
                                         #  4 #  7
#for line in fileinput.input('numberlines.py',inplace=True): #  5 #  8
#for line in fileinput.input(): #  for test #  9
for line in fileinput.input(inplace=True):
    line = line.rstrip()                 #  6 # 10
                                         #  7 # 11
    num = fileinput.lineno()             #  8 # 12
    print '%-40s # %2i' % (line,num)     #  9 # 13
