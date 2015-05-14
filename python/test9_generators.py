#!/usr/local/bin/python

nested = [[1,2],[3,4],[5,[6,7]]]

#def flatten(nested):
#    for sublist in nested:
#        for element in sublist:
#            yield element

def flatten(nested):
    try:
        for sublist in nested:
            for element in flatten(sublist):
                yield element
    except TypeError:
        yield nested

for num in flatten(nested):
    print num


g = ((i+2)*2 for i in range(2,27))
print g.next()
print range(3)
print sum(i**2 for i in range(3))


nestedch = [[1,2,'abc'],[3,4],[5,[6,7]]]
#nestedch = ['foo',['bar',['baz']]]

def flattench(nested):
    try:
        try:nested+''
        except TypeError:pass
        else:raise TypeError
        for sublist in nested:
            for element in flattench(sublist):
                yield element
    except TypeError:
        yield nested

for ch in flattench(nestedch):
    print ch

print flattench(nestedch)

r = flattench(nestedch)

print r.next()
print r.next()

def repeater(value):
    while True:
        new = (yield value)
        if new is not None:value = new

r = repeater(42)
print r.next()
print r.send("Hello")
print r.next()
        
