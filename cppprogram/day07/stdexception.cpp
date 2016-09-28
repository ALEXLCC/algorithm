#include<iostream>
using namespace std;
#include<exception>
int main(){
	try{
		double* p=new double[~0];
		cout<<p<<endl;
	}catch(exception& e){
		cout<<"exception type "<<e.what()<<endl;
	}
	cout<<"Oh Yeah..."<<endl;
	return 0;
}
