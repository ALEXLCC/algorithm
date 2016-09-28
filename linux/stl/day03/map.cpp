#include<iostream>
using namespace std;
#include<string>
#include<map>
int main(){
	map<int,string> mis;
	mis.insert(make_pair(62,"liling"));
	mis.insert(make_pair(32,"zhansan"));
	mis.insert(make_pair(36,"zhoukai"));
	mis[20]="jidongming";
	mis.insert(make_pair(32,"nana"));
	map<int,string>::iterator it=mis.begin();
	while(it!=mis.end()){
		cout<<it->first<<','<<it->second<<endl;
		++it;
	}
//	cout<<endl;
	return 0;
}
