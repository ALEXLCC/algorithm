/*
 *	file:myfirst.cc
 * */
#include<iostream>
#include<typeinfo>
#include"myfirst.hpp"
//using std::cout;
//using std::endl;
template<typename T>
void print_typeof(T const& x){
	std::cout<<typeid(x).name()<<std::endl;
}
