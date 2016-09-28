#include<iostream>
#include<string>
using namespace std;
class Phone{
	public:
		Phone(){
			cout<<"Phone constructed..."<<endl;
		}
		void call(string number){
			cout<<"call to "<<number<<endl;
		}
		void show(){
			cout<<"Phone show run..."<<endl;
		}
};
class Camera{
	public:
		Camera(){
			cout<<"Camera constructed..."<<endl;
		}
		void takephoto(string target){
			cout<<"take photo for "<<target<<endl;
		}
		void show(){
			cout<<"Camera show run..."<<endl;
		}
};
class CellPhone:public Phone,public Camera{
	public:
		CellPhone(){
			cout<<"CellPhone constructed..."<<endl;
		}
};
int main(){
	CellPhone nokia;
	nokia.Phone::show();
	nokia.call("alien");
	nokia.takephoto("mountains");
	return 0;
}
