#!/usr/local/bin/python

from collections import deque

a= deque([1,2,3,4,5])

a.rotate(-1)
print a
#print a.pop()
#print a.pop(3)
#print a
b = list([1,2,3,4,5])
print b
c = deque(b)
a.extend(c)
print a
