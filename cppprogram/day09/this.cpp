#include<iostream>
#include<cstdio>
using namespace std;
class A{
	public:
		void show(){
			cout<<this<<endl;
			printf("&this:%p\n",this);
		}
};
int main(){
	A a1,a2;
	cout<<&a1<<endl;
	cout<<&a2<<endl;
	a1.show();
	a2.show();
	return 0;
}
