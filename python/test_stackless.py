#!/usr/local/bin/python

#coding=utf-8
import time
import sys

#producer
def produce(l):
    print "start func produce"
    i=0
    while 1:
        if i < 5:
            l.append(i)
            print "yield %d" % i
            yield i
            i=i+1
            time.sleep(1)
        else:
            return

#consumer
def consume(l):
    print "start produce"
    p = produce(l)
    print "finish produce"
    while 1:
        try:
            print "start p.next"
            p.next()
            print "finish p.next"
            while len(l) > 0:
                print l.pop()
        except StopIteration:
            sys.exit(0)
l = []
consume(l)
