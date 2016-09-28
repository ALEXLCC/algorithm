#include<iostream>
using namespace std;
int main(){
	char a,b,c,d,e,f;
	cout<<"please input some characters:";
	a=cin.get();
	cin.get(b);
	cin.ignore();
	cin.get(c);
	d=cin.peek();
	cin.get(e);
	cin.putback(e);
	cin.get(f);
	cout<<a<<","<<b<<","<<c<<","<<d<<","<<e<<","<<f<<endl;
	return 0;
}
