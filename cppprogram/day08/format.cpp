#include<iostream>
using namespace std;
int main(){
	cout<<123.0<<endl;
//	cout<<showpoint<<123.0<<endl;
	cout.setf(ios::showpoint);
	cout<<123.0<<endl;
	cout.setf(ios::scientific|ios::uppercase);
	cout<<123.0<<endl;
	cout.unsetf(ios::scientific|ios::uppercase);
	cout.width(10);
	cout<<123<<endl;
	cout.setf(ios::left|ios::showpos);
	cout<<123.00<<endl;
	cout.setf(ios::fixed);
	cout.precision(8);
	cout<<123.456<<endl;
	return 0;
}
