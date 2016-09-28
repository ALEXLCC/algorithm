#include<iostream>
using namespace std;
class R{
	private:
		int n;
		int d;
	public:
		friend ostream& operator<<(ostream& out,const  R&x){
			return out<<x.n<<'/'<<x.d;
		}
		R(int n,int d=1):n(n),d(d){
			
		}
		~R(){}
		R& operator++(){
			n+=d;
			return *this;	
		}
		friend R operator++(R& r,int);
};
	 R operator++(R& r,int){
	 	R a(r.n,r.d);
		r.n+=r.d;
		return a;
	 }
int main(){
	R a(3,4);
	cout<<"a="<<++++a<<endl;
	cout<<"a++="<<a++<<"  a="<<a<<endl;
	return 0;
}
