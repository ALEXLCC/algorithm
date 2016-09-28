#!/usr/bin/python
#	len()	get length
#	max()	min()  get max min value
#	+ *	
#	in
#	cmp(str1,str2) compare two sequence  ,-1,0,1 equal   return 0 
str1='12345'
str2='abcde'
str1+=str2
print str2
print str1
print str1*3
print cmp(str1,str2)
print id(str1)
str1='46464'
print id(str1) 	# address has chenged
# cell group  ,not changeable like string
#just like struct
perInfo=("milo",20,"male") 	#add () usually
print type(perInfo)
print perInfo[0]
a,b,c=perInfo
print a
print b
print c
