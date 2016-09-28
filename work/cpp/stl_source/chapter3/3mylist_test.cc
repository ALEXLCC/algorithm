/*
 *	file: 3mylist_test.cc
 *	test 3mylist
 * */
int main(){
	List<int> mylist;
	for(int i = 0;i<5; ++i){
		mylist.insert_front(i);
		mylist.insert_end(i+2);
	}
	mylist.display();
	ListIter<ListItem<int> > begin(mylist.front());
	ListIter<ListItem<int> > end;	/* default 0, null */
	ListIter<ListItem<int> > iter;iter = find(begin,end,3);
	if(iter==end){
	
	}

	return 0;
}
