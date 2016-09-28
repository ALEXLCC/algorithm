/*
 *	file:1config_template_expp_special.cc
 *	test class template explicit specialization
 *	test __STL_TEMPLATE_NULL on <stl_config.h>
 *	ref. c++ Primer 3/e, p.858
 * */
#include<iostream>
using namespace std;
/*
 *	define __STL_TEMPLATE_NULL as twmplate<>,but if defined as blank ,only pass in gcc
 * */
#define __STL_TEMPLATE_NULL /* blank */
template<class Key> struct hash{
	void operator()(){
		cout<<"hash<T>"<<endl;
	}
};
//explicit specialization
template<>
__STL_TEMPLATE_NULL struct hash<char>{
	void operator()(){
		cout<<"hash<char>"<<endl;
	}
};
template<>
__STL_TEMPLATE_NULL struct hash<unsigned char>{
	void operator()(){
		cout<<"hash<unsigned char>"<<endl;
	}
};
int main(){
	hash<long> hl;
	hash<char> hc;
	hash<unsigned char> huc;
	hl();
	hc();
	huc();
	return 0;
}
