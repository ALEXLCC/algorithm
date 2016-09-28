/*
 *	file:1config_inclass_init.cc
 *	test in-class initialization of static const integeral members
 *	ref. C++ Primer 3/e. p.643
 * */
#include<iostream>
using namespace std;

template<typename T>
class testClass{
	public:	//expeditent
		static const int _datai=5;
		static const long _datal=3l;
		static const char _datac='c';
};
int main(){
	cout<<testClass<int>::_datai<<endl;	//5
	cout<<testClass<long>::_datal<<endl;	//3
	cout<<testClass<char>::_datac<<endl;	//c
	return 0;
}
