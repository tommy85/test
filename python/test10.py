#!/usr/local/bin/python

import sys

sys.path.append("/home/atmark/github/test/python")
#otherwise using export PYTHONPATH=$PYTHONPATH:~/XXX
#Do not need set PYTHONPATH when use module in current path  

#import drawing
from drawing import *
#import drawing.colors
#from drawing import shapes

#when use 'import drawing'
#print drawing.__all__
#print drawing.draw
#print drawing.drawone

#when use 'from drawing import *'
print draw
print drawone
funcdraw()
funcdrawone()
#print drawing.colors.color
#print shapes.shape
