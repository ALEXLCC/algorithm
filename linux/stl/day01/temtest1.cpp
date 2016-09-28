#include<iostream>
using namespace std;
template<class T>
void show(T const& d){
	cout<<d<<" ";
}
template<class T>
void show(T const* p){
	show(*p);
}
template<class T,int N>
void show(T (&a)[N]){
	for(int i=0;i<N;++i){
		show(a[i]);
	}
	cout<<endl;
}
int main(){
	int x=123;
	int arr[5]={1,2,3,4,5};
	int brr[2][4]={1,2,3,4,5,6,7,8};
	show(x);
	show(&x);
	show(arr);
	show(brr);
	show("hello");
	return 0;
}
