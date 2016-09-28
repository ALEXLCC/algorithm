#include<iostream>
using namespace std;
class Friend{
public:
	Friend(){
		cout<<"Friend constructed..."<<endl;
	}
	~Friend(){
		cout<<"Friend destructed..."<<endl;
	}
};
class Outer{
public:
	Outer(){
		cout<<"Outer constrcted..."<<endl;
	}
	~Outer(){
		cout<<"Outer destructed..."<<endl;
	}
class Inner{	//can't use static 
	public:
		Inner(){
			cout<<"Inner constructed..."<<endl;
		}
		~Inner(){
			cout<<"Inner destructed..."<<endl;
		}
		static void show(){
			cout<<"Outer::Inner::show()"<<endl;
		}
	};
	private:
		Friend f;
};
int main(){
	Outer o;
//	Outer::Inner i;
	Outer::Inner::show();
	return 0;
}
