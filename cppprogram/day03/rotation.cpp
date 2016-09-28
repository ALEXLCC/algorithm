#include<iostream>
using std::cout;
using std::endl;
class R{
	private:
		int n;	//numerator
		int d;	//denominator
	public:
		explicit R(int n,int d=1):n(n),d(d){
			cout<<"R("<<n<<"/"<<d<<")"<<endl;
		}
		~R(){
			cout<<"~("<<n<<"/"<<d<<")"<<endl;
		}
		R add(const R& r){
			int d1=d*r.d;
			int n1=d*r.n+n*r.d;
			return R(n1,d1);
		}
	   void	show(){
			cout<<n<<"/"<<d<<endl;
		}
};
int main(){
	R a(2,5), b(3,8);
	a.add(b).show();
	cout<<"________________________________"<<endl;
	a.add(R(3,4)).show();
	cout<<"________________________________"<<endl;
	cout<<"================================"<<endl;
//	a.add(3).show();
	cout<<"================================"<<endl;
	return 0;
}
