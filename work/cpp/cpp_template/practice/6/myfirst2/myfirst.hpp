/*
 *	file: myfirst.hpp
 *	global variable and function (non-inline) only declare in .hpp
 *	and implement in .cpp .C .cc .cxx .c
 * */
#ifndef MYFIRST_H
#define MYFIRST_H
#include<iostream>
#include<typeinfo>
using std::cout;
using std::endl;
template<typename T>
	void print_typeof(T const&);
template<typename T>
void print_typeof(T const& x){
	cout<<typeid(x).name()<<endl;
}
#endif
