#ifndef _SHOW_H_
#define _SHOW_H_
#include<iostream>
using std::endl;
using std::cout;
	template<class T>
	void show(T* arr,int len){
		for(int i=0;i<len;++i){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
#endif
