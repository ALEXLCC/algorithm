#include<iostream>
using namespace std;
void f1(int n)throw (int ,double){
	if(1==n){
		throw 123;
	}
	if(2==n){
		throw 4.5;
	}
	throw "out of range..";
}
void func(){
	cout<<"not in the exception table ..."<<endl<<endl<<endl;
}
int main(int argc,char* argv[]){
	set_unexpected(func);
	try{
		f1(argc);
	}catch(int e){
		cout<<"int "<<e<<endl;
		if(e>100){
			throw;	//throw again
		}
	}catch(double e){
		cout<<"double "<<e<<endl;
	}catch(...){
		cout<<"other ....."<<endl;
	}
	return 0;
}
