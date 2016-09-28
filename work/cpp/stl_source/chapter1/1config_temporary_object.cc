/*
 *	file: 1config_temporary_object.cc
 *	test for_each()
 * */
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
template<typename T>
class print{
	public:
		void operator()(const T& elem){	/* overload operator() */
			cout<<elem<<' ';
		}
};
/*
 *	when pass by value , always copy operator ,cause a temporary object
 *	typename()  ----> temporary object
 * */
int main(){
	int ia[6]={0,1,2,3,4,5};
	vector<int> iv(ia,ia+6);
//	print<int>();	//temporary object
	for_each(iv.begin(),iv.end(),print<int>());
	return 0;
}
