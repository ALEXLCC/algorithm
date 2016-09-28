#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	cout<<123.0<<endl;
//	cout<<showpoint<<123.0<<endl;
	cout<<scientific<<uppercase<<123.0<<endl;
	cout<<resetiosflags(ios::scientific)<<123.0<<endl;
	cout<<123<<endl;
	cout<<setw(10)<<123.00<<endl;
	cout<<setprecision(8)<<123.456<<endl;
	cout<<fixed<<setprecision(2)<<123.456778<<endl;
	cout<<setfill('#')<<setw(10)<<1234.567<<endl;
	return 0;
}
