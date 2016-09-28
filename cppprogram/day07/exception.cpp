#include<iostream>
using namespace std;
void fun(){
	throw 123;
	throw 4.6;
	throw "hello";
}
int main(){
	try{
		fun();
	}catch(int n){
		cout<<"int exception...code  "<<n<<endl;
	}
	return 0;
}
