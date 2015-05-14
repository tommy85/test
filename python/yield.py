#!/usr/local/bin/python

#coding=utf-8

#因为send必须在yield挂起后才有意义，故增加一个next先挂起consumer()的生成器

def coroutine(func):
    def ret():
        f = func()
        f.next()
        return f
    return ret
 
 
 
@coroutine
def consumer():
    print "Wait to getting a task"
    while 1:
        n = (yield)
        print "Got %s",n


#def ret():
#    f = consumer()
#    f.next()
#    return f
 
 
 
import time
def producer():
    c = consumer()
    while 1:
        time.sleep(1)
        print "Send a task to consumer"
        c.send("task")
 
if __name__ == "__main__":
    producer()
