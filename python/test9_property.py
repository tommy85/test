#!/usr/local/bin/python

__metaclass__ = type

class Rectangle:
    def __init__(self):
        self.width = 0
        self.height = 0
    def setSize(self,size):
        print "setSize"
        self.width,self.height = size
    def getSize(self):
        print "getSize"
        return self.width,self.height
    size = property(getSize,setSize)

r = Rectangle()
r.width = 10
r.height = 5

print r.size

r.size = 150,100
print r.width
