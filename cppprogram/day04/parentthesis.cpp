#include<iostream>
using namespace std;
class A{
	private:
	int* p;
	int len;
	public:
	A(int n,int v=0):p(new int[n]),len(n){
		for(int i=0;i<n;++i){
			p[i]=v;
		}
	}
	~A(){}
	A& operator()(int start,int step){
		for(int i=0;i<len;++i){
			p[i]=i*step+start;
		}	
		return *this;
	}
	int operator()(){
		int sum=0;
		for(int i=0;i<len;++i){
			sum+=p[i];
		}
		return sum;
	}
	friend ostream& operator<<(ostream& out,const A& a);
};
 ostream& operator<<(ostream& out,const A& a){
 	for(int i=0;i<a.len;++i){
		out<<a.p[i]<<' ';
	}
	return out;
 }
int main(){
	A a(9);
	a(5,1);	//a.operator()(5,1);
	cout<<a<<endl;
	return 0;
}
