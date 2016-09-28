#include<iostream>
using namespace std;
template<typename T,int N>
class A{
	public:
		void show()const{cout<<"generic"<<endl;}
		static const int v=A<T,N-1>::v+N;
};
template<class T>
class A<T,0>{
	public:
		void show(){cout<<"generic"<<endl;}
		static const int v=0;
};
template<class T,int N>
class A<T*,N>{
	public:
	void show()const{cout<<"pointer "<<N<<endl;}
};
template<int N>
class A<double,N>{
	public:
	void show()const{cout<<"double "<<N<<endl;}
};
int main(){
	cout<<A<int,10>::v<<endl;
	A<int,9>().show();
	A<double,10>().show();
	A<char,0>().show();
	A<char*,10>().show();
	return 0;
}
