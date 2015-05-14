#!/usr/local/bin/python

import shelve

s = shelve.open("test.txt")
s['x']=['a','b','c']
s['x'].append('d')
print s['x']

temp = s['x']
print temp
temp.append('d')
print temp
s['x'] = temp
print s['x']
s.close()
