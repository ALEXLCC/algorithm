/*
 *	file: 1config3.cc
 *	test class template contain static data members
 *	test __STL_STATIC_TEMPLATE_MEMBER_BUG,defined in <stl_config.h>
 *	ref c++ primer 3/e p.839
 *
 * *
 */
 #include<iostream>
 using namespace std;
 template <typename T>
 class testClass{
 	public:
		static int _data;
 };
 //define for static data member (allocate memory ,init)
template<>
int testClass<int>::_data=1;
template<>
int testClass<char>::_data=2;
 int main(){
 	cout<<testClass<int>::_data<<endl;
 	cout<<testClass<char>::_data<<endl;
	testClass<int> obji1,obji2;
	testClass<char> objc1,objc2;
	cout<<obji1._data<<endl;
	cout<<obji2._data<<endl;
	cout<<objc1._data<<endl;
	cout<<objc2._data<<endl;
	obji1._data=3;
	objc2._data=4;
	cout<<obji1._data<<endl;
	cout<<obji2._data<<endl;
	cout<<objc1._data<<endl;
	cout<<objc2._data<<endl;
 }
