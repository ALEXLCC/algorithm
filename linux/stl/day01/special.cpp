#include<iostream>
#include<cstring>
#include "show.h"
using namespace std;
template<typename T>
void _swap(T& a,T& b){
	T t=a;
	a=b;
	b=t;
}
/*
	
*/
template<class T>
//bool lessthan(const T& a,const T& b){
bool lessthan(T const& a,T const& b){
	return a<b;
}
/*
	special deal with
*/
bool lessthan(const char*& a,const char*& b){
	return strcmp(a,b)<0;
}
template<class T>
void sort(T* arr,int len){
	for(int i=0;i<len;++i){
		for(int j=i+1;j<len;++j){
			if(lessthan(arr[j],arr[i]))
			_swap(arr[i],arr[j]);
		}
	}
}
int main(){
	int ai[5]={6,1,4,5,7};
	double ad[5]={3.5,7.8,2.5,6.9,3.7};
	const char* ac[5]={"nice","to","meet","you","again"};
	sort(ai,5);
	sort(ad,5);
	sort(ac,5);
	show(ai,5);
	show(ad,5);
	show(ac,5);
	return 0;
}
