#!/usr/local/bin/python

#count = count + 1
#print count

#count[0] = count[0] + 1
#print count[0]

def hellocounter (name):
    count=[0]
    ###XXXcount=0
    def counter():
        count[0]+=1 ##use nonlocal in python3 nonlocal count +=1
        ###XXXXcount+=1
        print 'Hello,',name,',',str(count[0])+' access!'
        ###XXXprint 'Hello,',name,',',str(count)+' access!'
    return counter

hello = hellocounter('ma6174')
hello()
hello()
hello()  
