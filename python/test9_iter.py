#!/usr/local/bin/python

it = iter([1,2,3])

print it.next()

class Fibs:
    def __init__(self):
        self.a = 0
        self.b = 1
    def next(self):
        self.a,self.b = self.b,self.a+self.b
        return self.a
    def __iter__(self):
        return self

fibs = Fibs()

for f in fibs:
    if f > 1000:
        print f
        break

class MyIterator(object):
    def __init__(self,step,stop):
        self.step = step
        self.stop = stop
    def next(self):
        """Returns the next elements."""
        if self.step == self.stop:
            raise StopIteration
        self.step -= 1
        return self.step
    def __iter__(self):
        """Returns the iterator itself."""
        return self

for el in MyIterator(7,3):
    print el

print list(MyIterator(7,3))

for i in iter(range(10)):
    print i

print list(range(10))
print list(iter(range(10)))       
