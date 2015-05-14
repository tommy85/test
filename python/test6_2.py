#!/usr/local/bin/python

seq = ["foo","x41","?!","***"]

print filter(lambda x:x.isalnum(),seq)
