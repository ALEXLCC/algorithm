#include<iostream>
#include<cctype>
using namespace std;
istream& func(istream& input){
	cout<<"hello "<<endl;
	char c;
	do{
		input>>c;
	}while(!isdigit(c));
	input.putback(c);
	return input;
}
int main(){
	int n=-1;
//	func(cin);
//	cin>>n;
	cin>>func>>n;
	cout<<n<<endl;
	return 0;
}
