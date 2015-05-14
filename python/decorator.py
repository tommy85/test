#!/usr/local/bin/python

import time

def run_time(func):
    def wrapper(*args, **kwargs):
        start = time.time()
        r = func(*args, **kwargs)
        print time.time() - start
        return r
    return wrapper

#test = run_time(test)
@run_time
def test():
    print "just a test"

test()



def route(url):
    def decorator(func):
        func.__url__ = url
        return func
    return decorator

@route(r"/")
def index():
    return "Hi"


index.abc = 'hello'
print index()
print index.abc
if index is index:
    print 'yes'
#print index.__url__

def makebold(fn):
    def wrapped():
        return "<b>" + fn() + "</b>"
    return wrapped
 
def makeitalic(fn):
    def wrapped():
        return "<i>" + fn() + "</i>"
    return wrapped

@makebold
@makeitalic
def hello():
    return "hello world"

print hello()


