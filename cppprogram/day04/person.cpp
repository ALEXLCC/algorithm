#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
class P{
	private:
		string name;
		int age;
		float salary;
	public:
		P(const char*n="",int a=0,float s=0.0)
			:name(n),age(a),salary(s){}
		 operator string(){
			return this->name; 
		}
		 operator int(){
			return this->age;
		}
		 operator float(){
			return this->salary;
		}
};
int main(){
	P p1("alien",18,80000.0);
	string info=p1;
	int age=p1;
	double money=p1;
	cout<<info<<'\t'<<age<<'\t'<<money<<endl;
	return 0;
}
