#include<iostream>
using namespace std;
class R{
	private:
	int n;
	int d;
	public:
	R(int n1,int d1=1):n(n1),d(d1){
		if(d<0){
			d=-d;
			n=-n;
		}
		for(int i=d;i>1;--i){
			if(0==n%i&&0==d%i){
				d/=i;
				n/=i;
				break;
			}
		}
	}
	~R(){}
	R operator+(const R& r){
		return R(n*r.d+d*r.n,d*r.d);
	}
	friend ostream& operator<<(ostream& out,const R& r);
	friend istream& operator>>(istream& in,R& r);
};
istream& operator>>(istream& in,R& r){
	char c;
	return cin>>r.n>>c>>r.d;
}
ostream& operator<<(ostream& out,const R& r){
	return out<<r.n<<"/"<<r.d;	//call the overload function 
}
int main(){
	R a(6,8),b(8,-12);
	cout<<a<<b<<endl;
	cin>>a>>b;
//	cout<<(a+b)<<endl;
	operator<<(cout,a.operator+(b)).operator<<(endl);
	cout<<endl;
	return 0;
}
