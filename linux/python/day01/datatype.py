#!/usr/bin/python
#python is weak data type
#all variable is reference of a memory block
#integer float
nNum1=123
print type(nNum1)
nNum1=123344454567788990087655
print type(nNum1)
nNum1=123l
print type(nNum1)
nNum1=12.98
print type(nNum1)
nNum1=123.2337656778976789
print type(nNum1)
print type(0)
nNum1=2.13j
print type(nNum1)
nNum1='134'
print type(nNum1)
nNum1="12345"
print type(nNum1)
nNum1="""1234"""
# leave data as it is
print type(nNum1)
nNum1="""tom:
		I am jack
		goodbye
		"""
print nNum1
print type(nNum1)
nNum1='addf'
print nNum1[0]
print nNum1[1:4]
print nNum1[:2]
print nNum1[2:]	#2-->end
print nNum1[::]	#all
print nNum1[::2]	#step 2
print nNum1[-1]		#	f
print nNum1[-3:-1]	#dd
nNum1='fkhhkn gubvb'
print nNum1[-2:-5:-1]  #vbu
print nNum1[-2:-10:-2]	#vu k
# start end step
#if negative ,reverse the order
