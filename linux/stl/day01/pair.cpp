#include<iostream>
using namespace std;
template <class T,class V>
struct Pair{
	T first;
	V second;
	void show(){
		cout<<"template"<<endl;
	}
};
template<class K>
struct Pair<K,const char*>{
	K first;
	string second;
	void show(){
		cout<<"template___part__second__string"<<endl;
	}
};
template<class K>
struct Pair<const char*,K>{
	string first;
	K second;
	void show(){
		cout<<"template___part__first__string"<<endl;
	}
};
template<>	//total special type
struct Pair<const char*,char const*>{
	string first;
	string second;
	void show(){
		cout<<"total const char*"<<endl;
	}
};
template<class K,class V>
Pair<K,V> makePair(K k,V v){
	Pair<K,V> p={k,v};
	return p;
}
int main(){
	Pair<int,const char*> p1={9,"aaa"};
	Pair<int,int>p2={2,5};
	Pair<const char*,char const*> p3={"b","a"};
	p1.show();
	p2.show();
	p3.show();
	makePair(2,4).show();
	makePair("a","a").show();
	makePair("a",3).show();
	return 0;
}
