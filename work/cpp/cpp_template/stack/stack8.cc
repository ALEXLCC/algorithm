/*
 *	file:stack8.cc
 *	template of template actual argument
 * */
#include<iostream>
#include<vector>
#include<deque>
#include<stdexcept>
#include<memory>
using namespace std;
template<typename T,
		template<typename ELEM,typename =std::allocator<ELEM> > 
		class CONT=std::deque	>
class Stack{
	private:
		CONT<T> elems;
	public:
		void push(T const& );
		void pop();
		T top()const;
		bool empty() const{
			return elems.empty();
		}
		template<typename T2,
			template<typename ELEM2, typename =std::allocator<ELEM2> > class CONT2 >
			Stack<T,CONT>& operator= (Stack<T2,CONT2> const&);
};
template<typename T,template<typename,typename>class CONT >
void Stack<T,CONT>::push(T const& elem){
	elems.push_back(elem);
}
template<typename T,template<typename,typename>class CONT >
void Stack<T,CONT>::pop(){
	if(elems.empty()){
		throw std::out_of_range("Stack<>::pop(): empty stack");
	}
	elems.pop_back();
}
template<typename T,template<typename,typename>class CONT >
T Stack<T,CONT>::top()const{
	if(elems.empty()){
		throw std::out_of_range("Stack<>::pop(): empty stack");
	}
	return elems.back();
}
template<typename T,template<typename,typename>class CONT >
	template<typename T2,template<typename,typename>class CONT2 >
Stack<T,CONT>& Stack<T,CONT>::operator= (Stack<T2,CONT2> const& op2){
	if((void*)this==(void*)&op2){
		return *this;
	}
	Stack<T2,CONT2> tmp(op2);	/* copy  */
	elems.clear();
	while(!tmp.empty()){
		elems.push_front(tmp.top());
		tmp.pop();
	}
	return *this;
}
int main(){
	try{
		Stack<int> intStack;
		Stack<float> floatStack;
		intStack.push(42);
		intStack.push(7);
		floatStack.push(7.7);
		floatStack=intStack;
		/*------ use --------*/
		cout<<floatStack.top()<<endl;
		floatStack.pop();
		cout<<floatStack.top()<<endl;
		floatStack.pop();
		cout<<floatStack.top()<<endl;
		floatStack.pop();
		/**---------------**/
	}catch(std::exception const& ex){
		cerr<<"Exception: "<<ex.what()<<endl;
	}
	try{
		Stack<int,vector> intStack;
		Stack<float,vector> floatStack;
		intStack.push(42);
		intStack.push(7);
		floatStack.push(7.7);
//		floatStack=intStack;
		/*------ use --------*/
		cout<<intStack.top()<<endl;
		intStack.pop();
		cout<<intStack.top()<<endl;
		intStack.pop();
		cout<<intStack.top()<<endl;
		intStack.pop();
	}catch(std::exception const& ex){
		cerr<<"Exception: "<<ex.what()<<endl;
	}
	return 0;
}
