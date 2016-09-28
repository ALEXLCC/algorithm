#include<iostream>
using namespace std;
#include<deque>
int main(){
	deque<const char*>dcc;
	deque<const char*>::iterator it,ie;
	dcc.insert(dcc.begin(),"hello");
	dcc.insert(dcc.begin(),"csd1212");
	dcc.insert(dcc.end(),"welcome");
	ie=dcc.end();
	dcc.insert(--ie,"tarena");
	it=dcc.begin();
	ie=dcc.end();
	while(it!=ie){
		cout<<*it++<<' ';
	}
	cout<<endl;
	cout<<"size: "<<dcc.size()<<endl;
	cout<<"max_size: "<<dcc.max_size()<<endl;
	deque<const char*>::reverse_iterator ri;
	for(ri=dcc.rbegin();ri!=dcc.rend();++ri){
		cout<<*ri<<' ';
	}
	cout<<endl;
	while(!dcc.empty()){
		cout<<*dcc.begin()<<endl;
		dcc.erase(dcc.begin());
	}
	return 0;
}
