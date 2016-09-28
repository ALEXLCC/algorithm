#include<iostream>
#include<cstdlib>
using std::cout;
using std::endl;
class A{
	private:
		int data;
	public:
		A(int d=0):data(d){
			cout<<"A("<<data<<")"<<endl;
		}
		~A(){
			cout<<"~A()"<<data<<endl;
		}
		void* operator new(size_t bytes){
			cout<<"bytes="<<bytes<<endl;
			return malloc(bytes);
		}
		void operator delete(void* p){
			cout<<"free "<<p<<endl;
			free(p);
			p=NULL;
		}
};
int main(){
	A* p=new A;	//operator new(sizeof A);
	delete p;
	return 0;
}
