#!/usr/local/bin/python

import sys
print sys.argv
#print sys.modules
if 'sys' in sys.modules:
    print "have sys module"
args = sys.argv[1:]
args.reverse()
print ''.join(args)
