#include<iostream>
using namespace std;
class BST{
	public:
		int bst;
	public:
	BST(int bst){
		this->bst=bst;
		cout<<"BST constructed  "<<bst<<endl;
	}
	~BST(){
		cout<<"BST  "<<bst<<endl;
	}
};
class BalancedBST:public BST{
	public:
		int bbst;
	public:
		BalancedBST(int b,int bb):BST(b),bbst(bb){
			cout<<"BalancedBST constructed  "<<bbst<<endl;
		}
		~BalancedBST(){
			cout<<"BalancedBST  "<<bbst<<endl;
		}
};
void printBSTArray(ostream& s,const BST array[],int numElements){
	for(int i=0;i<numElements;++i){
		s<<array[i].bst<<' ';
	}
	cout<<endl;
}
void deleteArray(ostream& os,BST array[]){
	os<<"delete array at address "<<static_cast<void*>(array)<<endl;
	delete[] array;		//call ~ deconstructor
}
int main(){
	BST bsts[5]={1,3,5,7,9};
	BalancedBST bbst[5]={{1,2},{3,4},{5,6},{7,8},{9,10}};
	printBSTArray(cout,bbst,5);	
	/*
	 *	array[i]----->short of ----->*(array+i)
	 *	i-->sizeof class
	 *	BST--->virtual argument
	 *	BalancedBST------>actual argument
	 *	cast------->
	 *	array+i*sizeof BST------------------>bbst+i*sizeof BST  ---------------->error occur
	 * */
	deleteArray(cout,bbst);	//segment dump , pointer error
	return 0;
}
