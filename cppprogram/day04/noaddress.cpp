#include<iostream>
using std::cout;
using std::endl;
class NA{
	private:
		int n;
		double d;
	public:
		NA(){}
		~NA(){}
		NA* operator&(){
			return NULL;	//implict the address.
		}
};
int main(){
	NA a,b;
	cout<<&a<<endl;
	cout<<&b<<endl;
	return 0;
}
