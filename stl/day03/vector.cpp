#include<iostream>
using namespace std;
#include<vector>
int main(){
	vector<int> vi;
	cout<<"input scores,end by -1:"<<endl;
	int s,m=0;
	while(1){
		cin>>s;
		if(-1==s)
			break;
			vi.push_back(s);
			if(s>m){
				m=s;
			}
	}
	int inc=100-m;
	for(int i=0;i<vi.size();++i){
		vi[i]+=inc;
	}
	for(int i=0;i<vi.size();++i){
		cout<<vi[i]<<' ';	
	}
	cout<<endl;
	try{
	//	cout<<"vi[1000]= "<<vi[1000]<<endl;
		cout<<"vi.at(1000)= "<<vi.at(1000)<<endl;
	}catch(exception& e){
	//standard library exception all can use it
	//multi state , reference pointer
		cout<<e.what()<<endl;
	}
	return 0;
}
