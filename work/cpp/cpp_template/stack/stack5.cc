/*
 *	file:stack5.cc
 *
 * */
#include<iostream>
#include<deque>
using namespace std;
template<typename T>
class Stack{
	private:
		deque<T> elems;
	public:
		void push(T const&);
		void pop();
		T top() const;
		bool empty(){
			return elems.empty();
		}
		template<typename T2>
		Stack<T>& operator= (Stack<T2> const&);
};
template<typename T>
void Stack<T>::push(T const& t){
	elems.push_front(t);
}
template<typename T>
void Stack<T>::pop(){
	elems.pop_back();
}
template<typename T>
T Stack<T>::top()const{
	return elems.back();
}
template<typename T>
	template<typename T2>
Stack<T>& Stack<T>::operator= (Stack<T2> const& op2){
	if((void*)this==(void*)&op2){
		return *this;
	}
	Stack<T2> tmp(op2);
	elems.clear();
	while(!tmp.empty()){
		elems.push_front(tmp.top());
		tmp.pop();
	}
	return *this;
}
int main(){
	Stack<int> si;
	Stack<long> sl;
	sl=si;
	return 0;
}
