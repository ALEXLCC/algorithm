/*
 *	use string as a argument
 * */
#include<iostream>
#include<string>
using namespace std;
/*
template<typename T>
inline T const&  max(T const& x,T const& y){
	return x<y?x:y;
}
*/
template<typename T>
inline T max(T x,T y){
	return x<y?x:y;
}
template<typename T,int N,int M>
inline T const* max(T const (&x)[N],T const (&y)[M]){
	return x<y?x:y;
}
int main(){
	string s;
//	max("apple","peach");	/* call char const[6] is ambitous  */
	::max("apple","peach");	/* ok array----> pointer */
	::max("apple","tomato");	/* const char[6], const char[7]  */
	::max("apple",s);		/* const char[6], std::string& */
	return 0;
}
