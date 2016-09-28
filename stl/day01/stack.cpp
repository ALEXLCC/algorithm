#include<iostream>
using namespace std;
template <typename T>
class Stack{
	public:
		Stack():len(){
		}	
		void push(const T& d){
			arr[len++]=d;
		}
		T& pop(){
			if(0>=len){
				throw -1;
			}
			return arr[len--];
		}
		int size()const{
			return len;
		}
		bool empty()const{
			return 0==len;
		}
		bool full()const{
			return 10==len;
		}
		void show(){
			for(int i=0;i<len;++i){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
	private:
		T arr[10];
		int len;
};
int main(){
	Stack<int> si;
	Stack<const char*> ss;
	si.push(9);
	si.push(2);
	si.push(2);
	si.push(9);
	si.push(2);
	si.push(2);
	ss.push("hello");
	ss.push("world");
	ss.push("linux");
	ss.push("unix");
	ss.pop();
	si.show();
	ss.show();
	return 0;
}
