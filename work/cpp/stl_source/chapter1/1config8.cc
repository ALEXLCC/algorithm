/*
 *	file:1config8.cc
 *	test class template contain template (members)
 *	test __STL_MEMBER_TEMPLAATES in <stl_config.h>
 *	ref. c++ Primer 3/e, p.844
 * */
#include<iostream>

using namespace std;
class alloc{};
template<class T,class Alloc=alloc>
class vector{
	public:
		typedef T value_type;
		typedef value_type* iterator;
		template<class I>
		void insert(iterator position, I first,I last){
			cout<<"inseet() "<<endl;
		}
};
int main(){
	int ia[5]={0,1,2,3,4};
	vector<int> x;
	vector<int>::iterator ite;
	x.insert(ite,ia,ia+5);
	return 0;
}
