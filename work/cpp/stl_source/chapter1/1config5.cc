/*
 *	file:1config5.cc
 *	class template partial specialization 
 *	test __STL_CLASS_PARTIAL_SPECIALIZATION in <stl_config.h>
 *	ref. C++ Primer 3/e, p.860
 *	g++
 * */
#include<iostream>
using namespace std;
template<class I,class O>
struct testClass{
	testClass(){
		cout<<"I,O"<<endl;
	}
};
template<class T>
struct testClass<T*,T*>{
	testClass(){
		cout<<"T*,T*"<<endl;
	}
};
template<class T>
struct testClass<const T*,T*>{
	testClass(){
		cout<<"const T*,T*"<<endl;
	}
};
int main(){
	testClass<int,char>obj1;
	testClass<int*,int*>obj2;
	testClass<const int*,int*>obj3;
	return 0;
}
