/**
 *	file: 1config10.cc
 *	test temlate argument whether can have default value
 *	test __STL_LIMITED_DEFAULT_TEMPLATES in <stl_config.h>
 *	ref. c++ primer 3/e, p.816
 * */
#include<iostream>
#include<cstddef>
using namespace std;
class alloc{};
template<typename T,class Alloc=alloc,size_t BufSiz=0>
class deque{
	public:
		deque(){
			cout<<"deque"<<endl;
		}
};
template<typename T,class Sequence=deque<T> >
class stack{
	public:
		stack(){
			cout<<"stack"<<endl;
		}
	private:
		Sequence c;
};
int main(){
	stack<int> s;
	return 0;
}
