/*
 *	file: stack.cc
 *
 * */
#include<iostream>
#include<deque>
using namespace std;
template<typename T,
			template<typename ELEM> class CONT=std::deque >
/*
template<typename T,
			template<typename> class CONT=std::deque >	//also true
*/
class Stack{
	private:
		CONT<T> elems;
	public:
		void push(T const&);
		void pop();
		T top() const;
		bool empty() const{
			return elems.empty();
		}
};
template<typename T,template<typename> class CONT>
void Stack<T,CONT>::push(T const& elem){
	elems.push_back(elem);
}
template<typename T,template<typename> class CONT>
void Stack<T,CONT>::pop(){
	elems.pop_back();
}
template<typename T,template<typename> class CONT>
T Stack<T,CONT>::top() const{
	return elems.back();
}
int main(){
	Stack<int> si;
	return 0;
}
