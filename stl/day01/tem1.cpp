/*
	template not high effective
	template<typename T>
	template<class T>
*/
#include<iostream>
using namespace std;
#include<string>
template<typename T>
void sort(T* arr,int n){
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			if(arr[i]>arr[j]){
				T t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
			}
		}
	}
}
template<typename T>
void show(T* arr,int n){
	for(int i=0;i<n;++i){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int ai[6]={8,11,6,9,3,5};
	char ac[5]={'d','x','c','e','g'};
	double ad[6]={4.3,3.6,8.7,9.0,2.4,5.9};
	string as[4]={"anf","ryhyg","dgdgd","lfmhf"};
	sort(ai,6);
	sort(ac,5);
	sort(ad,6);
	sort(as,4);
	show(ai,6);
	show(ac,5);
	show(ad,6);
	show(as,4);
	return 0;
}
