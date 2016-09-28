/*
 *	file:1config_null_tempplate_arguments.cc
 *	test __STL_NULL_TMPL_ARGS in <stl_config.h>
 *	ref. C++ Primer 3/e, p.834: bound friend function template
 *
 * */
#include<iostream>
#include<cstddef>
using namespace std;
class alloc{};
template<typename T,class Alloc=alloc,size_t BufSiz=0>
class deque{
	public:
		deque(){
			cout<<"deque"<<' ';
		}
};
/*
 *	if this result not come out, g++ can pass. if come out, g++ can pass, too, which is not the same as c++ Primer 3/e p.834
 *	in the book, there must be a front declareation.
 * */
///*
template<class T,class Sequence>
class stack;
template<class T,class Sequence>
bool operator==(const stack<T,Sequence>& x,const stack<T,Sequence>& y);
template<class T,class Sequence>
bool operator<(const stack<T,Sequence>& x,const stack<T,Sequence>& y);
//*/
template<class T,class Sequence=deque<T> >
class stack{
	friend bool operator== <T> (const stack<T>&, const stack<T>&);
	friend bool operator< <T> (const stack<T>&, const stack<T>&);
//	friend bool operator== <T> (const stack&, const stack&);
//	friend bool operator< <T> (const stack&, const stack&);
//	friend bool operator== <> (const stack&, const stack&);
//	friend bool operator< <> (const stack&, const stack&);
//	friend bool operator==  (const stack&, const stack&)	//error
//	friend bool operator<  (const stack&, const stack&)		//error
	public:
		stack(){
			cout<<"stack"<<endl;
		}
	private:
		Sequence c;
};
template<class T,class Sequence>
bool operator== (const stack<T,Sequence>& x,const stack<T,Sequence>& y){
	return cout<<"operator=="<<'\t';
}
template<class T,class Sequence>
bool operator< (const stack<T,Sequence>& x,const stack<T,Sequence>& y){
	return cout<<"operator<"<<'\t';
}
int main(){
	stack<int> x;
	stack<int> y;	/* deque stack*/
	cout<<(x==y)<<endl;	//operator== 1
	cout<<(x<y)<<endl;	//operator< 1
	stack<char> y1;	//deque stack

	cout<<(x==y)<<endl;	//operator== 1
	cout<<(x<y)<<endl;	//operator< 1
	return 0;
}
