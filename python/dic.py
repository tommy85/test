#!/usr/local/bin/python
from copy import deepcopy

items = [('name','Gumby'),('age',[42])]
d = dict(items)
print d['name']

d['school']="zhongshan"

if 'school' in d :
    print "Found name"
else :
    print "can not found name"

x = d.copy()
c = deepcopy(d)
d['age'][0] = 43
#x['age'] = [43]
print d
print x
print c

print dict.fromkeys(['name','age'],'default')

iter = d.iteritems()
print list(iter)
print d.popitem()[1][0]
