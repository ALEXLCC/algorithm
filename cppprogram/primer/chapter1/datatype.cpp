#include<iostream>
using namespace std;
int main(){
	unsigned u=10;
	int i=-42;
	cout<<i+i<<endl;
	cout<<u+i<<endl;
	unsigned u1=42,u2=10;
	cout<<u1-u2<<endl;
	cout<<u2-u1<<endl;
//	const int con; //uninitialized	con
	const char* pc="csd";
	char* p=const_cast<char*>(pc);
	p[2]='M';
	cout<<p<<endl;
	for(u=10;u>0;--u){
		cout<<u<<endl;
	}
	return 0;
}
