/*
 *	file: addval.cc
 *	test for arguments
 * */
#include<iostream>
using namespace std;
template<typename T,int VAL>
T addValue(T const& x){
	return x+VAL;
}
template<int VAT>
double process(double v){
	return v*VAT;
}
/*
template<double VAT>
double process(double v){	//error  float number cannot as a non-type template argument
	return v*VAT;
}
*/
/*	class object cannot as a non-type template argument
 *
 *
 *	also string cannot as a template actual argument
 *	as string is a internal link object.
 *	two have same name but locate in defferent module is two different object.
 * */
/*
 *	template<char const* name>
 *	class MyClass{};
 *	MyClass<"hello"> x;	//error
 *
 *	template<char const* name>
 *	class MyClass{};
 *	char const* s="hello";
 *	MyClass<s> x;	//global pointer cannot as a argument  error
 *	
 *	template<char const* name>
 *	class MyClass{};
 *	extern char const s[]="hello";
 *	MyClass<s> x;	//ok
 * */
int main(){
	int a=addValue<int,20>(3);
	double d=process<3>(4);
	cout<<a<<endl<<d<<endl;
	return 0;
}
