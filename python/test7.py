#!/usr/local/bin/python

#print "Hello" + repr(1)
#print 1

__metaclass__ = type

class Person:
    #__name = ''
    #name = ''
    def __init__(self):
        self.name = "default name"
    def setName(self,name):
        self.name = name
        #Person.__name = name

    def getName(self):
        return self.name
        #return Person.__name
    
    def greet(self):
        print "Hello,world! I'm %s." % self.name
        #print "Hello,world! I'm %s." % Person.__name

class Son(Person):
    def __init__(self):
        super(Son,self).__init__()
        pass
    def greet(self):
        print "Hello,son!I'm %s." % self.name

foo = Person()
bar = Person()
son = Son()

#foo.setName('zhangteng')
foo.name = 'zhangteng'
bar.setName('abc')
#son.setName("xiaoxiao")

foo.greet()
bar.greet()
son.greet()

print type(foo)
print type(son)

#print foo.__name
#print foo._Person__name
