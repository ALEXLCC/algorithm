/*	
 *	file: stack_t.cc
 *	stack template use vector
 *	note: local special
 *	template <typename T,typename K>
 *	class MyClass{};
 *	
 * */
#include<iostream>
#include<vector>
#include<deque>
#include<stdexcept>
#include<cstdlib>
#include<string>
using namespace std;
template <typename T>
class Stack{
	private:
		vector<T> elems;
	public:
	/*
	 *	Stack (Stack<T> const&);	use class name not class type. destructor the same .
	 *	Stack<T>& operator= (Stack<T> const&);
	 * */
		void push(T const&);
		void pop();
		T top() const;
		inline bool empty()const{
			return elems.empty();
		}
};
template <typename T>
void Stack<T>::push(T const& elem){
	elems.push_back(elem);
}
template <typename T>
void Stack<T>::pop(){
	if(elems.empty()){
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	elems.pop_back();
}
template <typename T>
T Stack<T>::top()const{
	if(elems.empty()){
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	return elems.back();
}
typedef Stack<string> StringStack;
template <>
class Stack<string>{
	private:
		deque<string> elems;
	public:
	/*
	 *	Stack (Stack<T> const&);	use class name not class type. destructor the same .
	 *	Stack<T>& operator= (Stack<T> const&);
	 * */
		void push(string const&);
		void pop();
		string top() const;
		inline bool empty()const{
			return elems.empty();
		}
};
void Stack<string>::push(string const& elem){
	elems.push_back(elem);
}
void Stack<string>::pop(){
	if(elems.empty()){
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	elems.pop_back();
}
string Stack<string>::top()const{
	if(elems.empty()){
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	return elems.back();
}
int main(){
	try{
		Stack<int> intStack;
		Stack<string> stringStack;
		intStack.push(7);
		stringStack.push("hello");
		cout<<stringStack.top()<<endl;
		StringStack ss;
		ss.push("aaa");
		stringStack.pop();
		stringStack.pop();
	}catch(exception const& ex){
		cerr<<"Exception:"<<ex.what()<<endl;
		return EXIT_FAILURE;
	}
	return 0;
}
