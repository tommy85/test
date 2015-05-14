#!/usr/local/bin/python

class TestClassMethod(object):

    METHOD = 'method hoho'

    def __init__(self):
        self.name = 'leon'

    def test1(self):
        print 'test1'
        print self
        print self.name

    @classmethod
    def test2(cls):
        print cls
        print 'test2'
        print TestClassMethod.METHOD
        print '----------------'
        #print self.name XXXXX

    @staticmethod
    def test3():
        print TestClassMethod.METHOD
        print 'test3'
        #print self.name XXXXXX

if __name__ == '__main__':
    a = TestClassMethod()
    a.test1()
    a.test2()
    a.test3()
    print '*'*20
    TestClassMethod.test2()
    TestClassMethod.test3()
