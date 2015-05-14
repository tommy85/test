wwwwww#!/usr/local/bin/python
from math import pi 

print '%20f' %pi

print '%-20f,abc' %pi

print '%-.2f' %pi

print "%.5s" % "zhangteng"

print '%020f' %pi

print ('% 5d'%10)+'\n'+('% 5d'%-10)

print ('%+5d'%10)+'\n'+('%+5d'%-10)

print ('%-5d'%10)+'\n'+('%-5d'%-10)

header_format ='%-*s%*s'
format = '%-*s%*.2f'

item_width = 5
price_width = 10
print format %(item_width,'Apples',price_width,0.4)
