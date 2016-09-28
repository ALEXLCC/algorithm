#include<iostream>
using std::cout;
using std::cin;
using std::endl;
inline int max(int a,int b){
	return a<b?a:b;
}
int main(){
	int a=9;
	int b=10;
	cout<<"max:"<<max(a,b)<<endl;
}
