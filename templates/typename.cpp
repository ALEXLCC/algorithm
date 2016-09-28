/*
 *	template
 *	typename 
 *	.template
 *
 * */
#include<iostream>
#include<vector>
using namespace std;
template<typename T>
void printcoll(T const& coll){
	typename T::const_iterator pos;
	typename T::const_iterator end(coll.end);
	for(pos=coll.begin();pos!=end;++pos){
		cout<<*pos<<' ';
	}
	cout<<endl;
	return ;
}
template<int N>
void printBitset(std::bitset<N> const& bs){
	cout<<bs.template to_string<char,char_traits<char>,allocator<char> >();
}
int main(){
	vector<int> v(5,0);
	v.push_back(3);
	printcoll<vector>(v);
	return 0;
}
