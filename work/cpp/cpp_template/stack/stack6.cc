/*
 *	file:stack6.cc
 *
 * */
#include<iostream>
#include<deque>
using namespace std;
template<typename T,typename CONT=deque<T> >
class Stack{
	private:
		CONT elems;
	public:
		void push(T const&);
		void pop();
		T top() const;
		bool empty(){
			return elems.empty();
		}
		template<typename T2,typename CONT2>
		Stack<T,CONT>& operator= (Stack<T2,CONT2> const&);
};
template<typename T,typename CONT>
void Stack<T,CONT>::push(T const& t){
	elems.push_front(t);
}
template<typename T,typename CONT>
void Stack<T,CONT>::pop(){
	elems.pop_back();
}
template<typename T,typename CONT>
T Stack<T,CONT>::top()const{
	return elems.back();
}
template<typename T,typename CONT>
	template<typename T2,typename CONT2>
Stack<T,CONT>& Stack<T,CONT>::operator= (Stack<T2,CONT2> const& op2){
	if((void*)this==(void*)&op2){
		return *this;
	}
	Stack<T2,CONT2> tmp(op2);
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
