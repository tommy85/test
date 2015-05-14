#!/usr/local/bin/python

a = 3
b = False
c = 5

print a if b else c

for number in range(1,11):
    print number

d = {'x':1,'y':2,'z':3}

print d.keys()
print d.values()
for key in d:
    print key,'corresponds to',d[key]

print list(reversed("Hello"))
print ''.join(reversed("Hello"))

for ch in reversed("Hello"):
    print ch,
#    print(ch,end=" ")
x
