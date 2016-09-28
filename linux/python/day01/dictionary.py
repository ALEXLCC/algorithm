#!/usr/bin/python
#list  is orderable index now allowed beyond
#dictionary  hashtable map
# {key->value} 
# dict() dict(['',''],[,])
# {}.fromkeys((,)-1)
# pop delete and return the top value dic.pop('a')
#dic.clear()	delete all elements
#del dic  delete total dictionary
#dict.get(key,default=None)
#dict.has_ke(key)
#dict.items()
#dict.keys()
#dict.iteritems(),iterkeys((),itervalues()
#dict.setdefault()
#dict.update(dict2)
#dict.values()	return all values list
#update copy a dic to another
t=['name','age','gender']
t2=['mail',30,'male']
print t2[0]
dic={0:0,1:1,2:2}
print dic
print id(dic)
dic={'name':'milo','age':23,'gender':'male'}
print dic
print id(dic)
a=123
b=456
dic={a:'aaa',b:'bbb'}
print dic
print id(dic)
for k in dic:
	print k
for k in dic:
	print dic[k]
