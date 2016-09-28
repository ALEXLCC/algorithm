#include<iostream>
#include<cstring>
using std::cout;
using std::endl;
int main(){
	int* pi=new int;
	int n=200;
	char* pc=new char[n];
	double* pd=new double[0xf000];
	long* pl=new long(123);
	short* ps=new short();
	*pi=12*101;
	strcpy(pc,"alien");
	pd[10]=123.45;
	cout<<*pi<<","<<pc<<","<<pd[10]<<","<<*pl<<","<<*ps<<endl;
	delete pi;
	delete[] pc;
	delete[] pd;
	delete pl;
	delete ps;
	return 0;
}
