/*
 *	file:ad1.cc
 *	Ref. C++ Templates 9.2 p.120
 * */
#include<iostream>
namespace X{
	template<typename T>
		void f(T);
}
namespace N{
	using namespace X;
	enum E{
		e1
	};
	void f(E){
		std::cout<<"N::f(N::E) called\n";
	}
}
void f(int){
	std::cout<<"::f(int) called\n";
}
int main(){
	::f(N::e1);
	f(N::e1);
	return 0;
}
