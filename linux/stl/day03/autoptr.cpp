#include<iostream>
using namespace std;
#include<memory>
int main(){
	auto_ptr<int> pi(new int(1024));
	if(*pi!=1024){

	}else{
		*pi*=2;
	}
	auto_ptr<int> p2(new int(2048));
	pi=p2;
	cout<<"&p2"<<(&p2)<<endl;
	cout<<"&p1"<<(&pi)<<endl;
	return 0;
}

