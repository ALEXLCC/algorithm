#!/usr/bin/python
# True False
#False  0  None  blank element
def fun():
	return 1
x=int(raw_input("please input :"))
y=int(raw_input("please input :"))
if x>=90 and y>=90:
	print 'A'
elif x>=80 or y>=80:
	print 'B'
elif x>=70 or not y>70:
	print 'C'
elif x>=60:
	print 'D'
else:
	print 'bad'
print 'Main ok'
