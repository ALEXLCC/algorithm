#!/usr/bin/python
# xrange()  iterator 
#range(i,j,[step]) default i,0,,j 1	not contain j
for x in 'abcd':
	print x,'hello world'
for x in [0,1,2,3,4,5,6]:
	print x,'hello world'
for x in range(100):
	print x,'hello world'
for x in range(1,11,2):
	print x,'hello world'
fruits=['banana','apple','mango']
for fruit in fruits:
	print 'Current fruit:',fruit
print 'GoodBye!'
