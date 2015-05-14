#!/usr/local/bin/python
import random

def conflict(state,nextX):
    nextY = len(state)
    for i in range(nextY):
        if abs(state[i]-nextX) in (0,nextY-i):
            return True
    return False

def queens(num=8,state=()):
    for pos in range(num):
        if not conflict(state,pos):
            if len(state) == num-1:
                yield (pos,)
            else:
                for result in queens(num,state+(pos,)):
                    yield(pos,)+result

#print list(queens(4))

def prettyprint(solution):
    def line(pos,length=len(solution)):
        return '. '*(pos) + 'X ' +'. '*(length-pos-1)
    for pos in solution:
        print line(pos)

#prettyprint(random.choice(list(queens(8))))

#for solution in queens(4):
#    print solution

r = queens(4,(2,))
print r.next()
