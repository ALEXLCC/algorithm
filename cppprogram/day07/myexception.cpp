#include<iostream>
#include<cstdio>
using namespace std;
#include<exception>
#include<new>
class A{
	private:
		int *p;
		int len;
	public:
		explicit A(int n)throw(){
			p=new (nothrow)int[n];
			len=n;
		}
		int& operator[](int index){
			if(index<0){
				throw NegIndex(index);
			}
			if(index>=len){
				throw new OutOfRange(index);
			}
			if(NULL==p){
				throw MemoryException();
			}
			return p[index];
		}
		class NegIndex:public exception{
			private:
				int index;
			public:
				NegIndex(int index):index(index){}
				const char* what()const throw(){
//					char buf[];//not safe  return the memory will be free
					static char buf[100];
					sprintf(buf,"negative index %d\n",index);
					return buf;
				}
		};
		class OutOfRange:public exception{
			private:
				int index;
			public:
				OutOfRange(int index):index(index){}
				const char* what()const throw(){
					static char buf[100];
					sprintf(buf,"out of range index %d\n",index);
					return buf;
				}
		};
		class MemoryException:public exception{
				public:
					const char* what()const throw(){
						return "memory is not enough..\n";
					}
		};
};
int main(){
	A x(10);
	x[0]=5;
	x[3]=10;
	x[8]=20;
	cout<<x[3]*x[0]*x[8]<<endl;
	cout<<x[-1];
	cout<<x[19];
	return 0;
}
