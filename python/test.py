#!/usr/local/bin/python

#name = raw_input("What is your name?\n")

#print "Hello," + name

#x = ['name','zhangteng','houhou']
#x.sort(key=len,reverse=True)
##x.reverse()
#print x

#print "Hello,%d,zhangteng,%d" % (3,4)

#seq = "12345"
#sep = '+'
#print sep.join(seq) + "=" + repr(5)
from string import maketrans

#import string

table = maketrans('az','kt')
#print table

#print maketrans('', '')[97:123]

str = "I am zhangteng"
print str.translate(table)

print range(0,10)

print 'Hello'+' '+'world'
print 'Hello','world'
print 'Hello',4
#XXXXXprint 'Hello'+4
