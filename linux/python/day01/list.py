#!/usr/bin/python
#list []  number string cell group   ,,changabble
#cell group ()
#change all cell group value ,--> declare a new cell group
# del  remove
# append 
# modify  list[]
# find 
lList=[]
print type(lList)
print id(lList)
lList=['milo',30,'male']
print id(lList[1])
lList[1]=32
print id(lList[1])
print id(lList)
print lList[1]
lList.append('ajdnn')
print lList
lList.remove('male')
print lList
