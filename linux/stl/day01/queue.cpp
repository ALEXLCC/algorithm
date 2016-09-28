#include<iostream>
using namespace std;
template <typename T,int N>
class Queue{
	public:
		Queue():len(){
		}	
		Queue& push(const T& d){
			if(len>=N){
				throw "full";
			}
			arr[len++]=d;
			return *this;
		}
		void pop(){
			for(int i=1;i<len;++i){
				arr[i-1]=arr[i];
			}
			--len;
		}
		T& front(){
			return arr[0];
		}
		T& rear(){
			return arr[len];
		}
		int size()const{
			return len;
		}
		bool empty()const{
			return 0==len;
		}
		bool full()const{
			return 10==N;
		}
		void show(){
			for(int i=0;i<len;++i){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
	private:
		T arr[N];
		int len;
};
int main(){
	Queue<int,10> si;
	Queue<const char*,20> ss;
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
	cout<<ss.front()<<endl;
	cout<<ss.rear()<<endl;
	return 0;
}
