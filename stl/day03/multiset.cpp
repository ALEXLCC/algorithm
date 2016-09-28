#include<iostream>
using namespace std;
#include<set>
template<class Iter>
void show(Iter ib,Iter ie){
	while(ib!=ie){
		cout<<*ib++<<' ';
	}
	cout<<endl;
}
int main(){
	int a[5]={5,1,7,5,1};
	multiset<int> pids(a,a+5);
	show(pids.begin(),pids.end());
	show(pids.lower_bound(1),pids.upper_bound(1));
	pids.insert(7);
	pids.insert(7);
	pids.insert(7);
	pids.erase(pids.find(5));
	show(pids.begin(),pids.end());
	cout<<"end process 7:"<<endl;
	pids.erase(7);
	show(pids.begin(),pids.end());
	return 0;
}
