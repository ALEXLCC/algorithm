/*
 *	implement of the list functions
 * */
#include<stdlib.h>
#include<string.h>
#include "list.h"
/*
 *	initialize the list.
 * */
void list_init(List * list,void (*destroy)(void * data)){
	list->size=0;
	list->destroy=destroy;
	list->head=NULL;
	list->tail=NULL;
}
/*
 *	list_destroy
 * */
void list_destroy(List* list){
	void * data;
	/*remove each element
	 * */
	while(list_size(list)){
		/*list->size>0*/
		if(list_rem_next(list,NULL))
	}
}
