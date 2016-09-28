#!/usr/bin/python
s='hello'
l=[1,2,3,'a','b']
t=(7,8,9,'x','y')
d={1:111,2:222,5:555,3:333}
for x in range(len(s)):
	print s[x]
for x in l:
	print x
for x in d:
	print x,d[x]
for k,v in d.items():
	print k,v
