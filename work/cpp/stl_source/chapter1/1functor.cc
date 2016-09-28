/*
 *	file: 1functor.cc
 *
 * */
#include<iostream>
using namespace std;
/*
 *	use operator() override ,so plus become a functor
 * */
template<class T>
struct plus{
	T operator()(const T&x,const T& y){
		return x+y;
	}
};

/*
 *	use operator() override ,so minus become a functor
 * */
template<class T>
struct minus{
//	minus(){}
	T operator()(const T&x,const T& y){
		return x-y;
	}
};
int main(){
	plus<int> plusobj;	/*functor object */
	minus<int> minusobj;	/*functor object */
	/*
	 *	use functor as a fuunction
	 * */
	cout<<plusobj(3,5)<<endl;
	cout<<minusobj(3,5)<<endl;
	/*
	 *	generate a functor object temporary object and call it
	 * */

	cout<<plus<int>()(33,45)<<endl;
	cout<<minus<int>()(43,35)<<endl;
	return 0;
}
