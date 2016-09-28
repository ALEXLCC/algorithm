/*
 *	file: 3mylist.cc
 * */
#include "3mylist.h"
template<typename Item>
struct ListIter{
	Item* ptr;
	ListIter(Item* p = 0): ptr(p) {}
	/*
	 *	use default copy constructor
	 *	using default operator=
	 * */
	Item& operator*() const {
		return *ptr;
	}
	Item* operator->() const {
		return ptr;
	}
	ListIter& operator++() {
		ptr=ptr->next();
		return *this;
	}
	ListIter operator++(int){
		ListIter tmp = *this;
		++*this;
		return tmp;
	}
	bool operator==(const ListIter& i) const {
		return ptr == i.ptr;
	}
	bool operator!=(const  ListIter& i) const {
		return ptr != i.ptr;
	}
};
