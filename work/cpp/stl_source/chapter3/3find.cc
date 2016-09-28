/*
 *	file:2find.cc
 *	Ref. The Annotated STL Source. P.80
 * */
#include<vector>
#include<list>
#include<deque>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	const int arraySize=7;
	int ia[arraySize]={0,1,2,3,4,5,6};
	vector<int> ivect(ia,ia+arraySize);
	deque<int> ideque(ia,ia+arraySize);
	list<int> ilist(ia,ia+arraySize);
	vector<int>::iterator it1=find(ivect.begin(),ivect.end(),4);
	if(it1==ivect.end()){
		cout<<"4 not found."<<endl;
	}else{
		cout<<"4 found."<<*it1<<endl;
	}
	/*
	 *	result 4 found. 4
	 * */
	deque<int>::iterator it2=find(ideque.begin(),ideque.end(),6);
	if(it2==ideque.end()){
		cout<<"6 not found."<<endl;
	}else{
		cout<<"6 found."<<*it2<<endl;
	}
	/*
	 *	result 6 found. 6
	 * */
	list<int>::iterator it3=find(ilist.begin(),ilist.end(),8);
	if(it3==ilist.end()){
		cout<<"8 not found."<<endl;
	}else{
		cout<<"8 found."<<*it3<<endl;
	}
	/*
	 *	result 8 found.
	 * */
	return 0;
}
