/*
 *	file:this.cc
 *	x  this->x
 * */
#include<iostream>
using std::cout;
using std::endl;
template<typename T>
class Base{
	public:
		void exit();
};
template<typename T>
void Base<T>::exit(){
	cout<<"exit call"<<endl;
}
template<typename T>
class Derived: public Base<T>{
	public:
		void foo(){
/*			exit();//no arguments  call sys exit  not consider Base::exit	*/
			this->exit();
		}
};
int main(){
	Derived<int> d;
	d.foo();
	return 0;
}
