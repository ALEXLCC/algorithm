#include<iostream>
using namespace std;
#include<set>
int main(){
	set<int> si;
	int userid[5]={3,8,6,1,2};
	for(int i=0;i<5;++i){
		si.insert(userid[i]);
	}
	set<int>::iterator it;
	it=si.begin();
	while(it!=si.end()){
		cout<<*it++<<' ';
	}
	cout<<endl;
	cout<<"user 3:"<<(si.find(3)!=si.end())<<endl;
	cout<<"user 5:"<<(si.find(5)!=si.end())<<endl;
	si.erase(8);
	it=si.begin();
	while(it!=si.end()){
		cout<<*it++<<' ';
	}
	cout<<endl;
	return 0;
}
