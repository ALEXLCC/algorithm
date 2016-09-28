#include<iostream>
#include<string>
using namespace std;
void printDouble(const double& rd){
	cout<<rd;
}
void printDouble_p(const double* pd){
	if(fd){
		cout<<*pd;
	}
}
int main(){
	//
	char* pc=0;		//NULL pointer
	char& rc=*pc;
	//
	//
	string& rs;		//error ,not init
	string s("xyzzy");
	string& rs=s;
	//
	//
	string* ps;		//where to point to
	//
	//
	string s1("Nancy");
	string s2("Clancy");
	string& rs=s1;
	string* ps=&s1;
	rs=s2;			//rs---->s1   s1==Clancy
	ps=s2;			//ps--->s2    s1=Nancy
	//
	return 0;
}
