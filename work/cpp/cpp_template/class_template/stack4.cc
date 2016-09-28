/*
 *	file stack4.cc
 *	test for non-type argument
 * */
#include<stdexcept>
#include<string>
#include<cstdlib>
#include<iostream>
using namespace std;
template<typename T,int MAXSIZE>
class Stack{
	private:
		T elems[MAXSIZE];
		int numElems;
	public:
		Stack();
		void push(T const&);
		void pop();
		T top() const;
		bool empty()const{
			return numElems==0;
		}
};
template<typename T,int MAXSIZE>
Stack<T,MAXSIZE>::Stack():numElems(0){
	
}
template<typename T,int MAXSIZE>
void Stack<T,MAXSIZE>::push(T const& elem){
	if(numElems==MAXSIZE){
		throw std::out_of_range("Stack<>::push(): stack is full");
	}
	elems[numElems]=elem;
	++numElems;
}
template<typename T,int MAXSIZE>
void Stack<T,MAXSIZE>::pop(){
	if(numElems<=0){
		throw std::out_of_range("Stack<>::push(): stack is empty");
	}
	--numElems;
}
template<typename T,int MAXSIZE>
T Stack<T,MAXSIZE>::top() const{
	if(numElems<=0){
		throw std::out_of_range("Stack<>::push(): stack is empty");
	}
	return elems[numElems-1];
}
int main(){
	try{
		Stack<int,20> int20Stack;
		Stack<int,40> int40Stack;
		Stack<string,40> stringStack;
		int20Stack.push(8);
		cout<<int20Stack.top()<<endl;
		int20Stack.pop();
		stringStack.push("hello");
		cout<<stringStack.top()<<endl;
		stringStack.pop();
		stringStack.pop();
	}catch(std::exception const& ex){
		cerr<<"Exception "<<ex.what()<<endl;
		return EXIT_FAILURE;
	}
	return 0;
}
