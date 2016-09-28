/*
 *	file: default_template.cc
 *	if only convert the first argument , the second will use the default [vector]
 * */
#include<iostream>
#include<vector>
#include<deque>
#include<stdexcept>
using namespace std;
template <typename T,typename CONT=vector<T> >
class Stack{
	private:
	CONT elems;
	public:
	void push(T const&);
	void pop();
	T top() const;
	bool empty()const{
		return elems.empty();
	}
};
template<typename T,typename CONT>
void Stack<T,CONT>::push(T const& elem){
	elems.push_back(elem);
}
template <typename T,typename CONT>
void Stack<T,CONT>::pop(){
	if(elems.empty()){
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	elems.pop_back();
}
template<typename T,typename CONT>
T Stack<T,CONT>::top() const{
	if(elems.empty()){
		throw out_of_range("Stack<>::top(): empty stack");
	}
	return elems.back();
}
int main(){
	try{
		Stack<int> intStack;
		Stack<double,deque<double> > dblStack;
		/*
		 *	deque<double>>	>>  cin >>   stream insert symbol
		 * */
		intStack.push(7);
		cout<<intStack.top()<<endl;
		intStack.pop();
		dblStack.push(42.42);
		cout<<dblStack.top()<<endl;
		dblStack.pop();
		dblStack.pop();
	}catch(exception const& ex){
		cerr<<"Exception: "<<ex.what()<<endl;
	}
	return 0;
}
