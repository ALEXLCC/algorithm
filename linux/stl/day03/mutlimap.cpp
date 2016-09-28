#include<iostream>
using namespace std;
#include<map>
#include<string>
int main(){
	typedef multimap<string,string> M;
	M mss;
	M::iterator ib,ie;
	mss.insert(make_pair("aa","ab"));
	mss.insert(make_pair("cc","ac"));
	mss.insert(make_pair("dd","ad"));
	mss.insert(make_pair("cc","ae"));
	mss.insert(make_pair("aa","af"));
	mss.insert(make_pair("cc","ae"));
	ib=mss.begin();
	ie=mss.end();
	while(ib!=ie){
		cout<<ib->first<<','<<ib->second<<endl;
		++ib;
	}
	cout<<"aa count   "<<mss.count("aa")<<endl;
	cout<<"cc count   "<<mss.count("cc")<<endl;
	cout<<"dd count   "<<mss.count("dd")<<endl;
	ib=mss.lower_bound("cc");
	ie=mss.upper_bound("cc");
	while(ib!=ie){
		cout<<ib->first<<','<<ib->second<<endl;
		++ib;
	}
	return 0;
}
