#!/usr/local/bin/python

import exceptions

#print dir(exceptions)

#raise ZeroDivisionError("zero exception")

class CustomException(Exception):
    str = "caonima"
    def hehe(self):
        print self.str
        

while True:
    try:
        x = input('first number:')
        y = input('second number:')
        raise CustomException("zhangteng exception")
        print x/y
    #except ZeroDivisionError,e:
    #    print e
    #    print "The second number can't be zero!"
    #except TypeError:
    #    print "That wasn't a number."
    #except (ValueError,NameError),e:
    #    print e
    except CustomException,e:
       e.hehe()
    except Exception,e:
        e.hehe()
        print 'Invalid input',e
        print 'try again'
    else:
        break
    finally:
        print "clean up"
