/*
 *	file:locale_template.cc
 *
 * *
 */
#include<iostream>
using namespace std;
template<typename T,typename K>
class MyClass{
	public:
	T t_data;
	K k_data;
};
template<typename T>
class MyClass<T,T>{
	public:
	T t_data;
	T k_data;
};
template <typename T>
class MyClass<T,int>{
	public:
	T t_data;
	int k_data;
};
template<typename T,typename K>
class MyClass<T*,K*>{
	public:
	T* t_data;
	K* k_data;
};
int main(){
	MyClass<int,float> mif;
	MyClass<long,long> mll;
	MyClass<float,int> mfi;
	MyClass<int*,float*> mipfp;
	return 0;
}
