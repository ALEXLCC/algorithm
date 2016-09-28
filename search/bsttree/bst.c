/*
 	bst.c
 */
#include<stdlib.h>
#include<stdio.h>
#include "bst.h"
static link make_node(unsigned char elem){
	link p=malloc(sizeof *p);
	p->elem=elem;
	p->l=p->r=NULL;
	return p;
}
static void free_node(link p){
	free(p);
}
link search(link t,unsigned char elem){
	if(!t){
		return NULL;
	}
	if(t->elem>elem){
		return search(t->l,elem);
	}
	if(t->elem<elem){
		return search(t->r,elem);
	}
	return t;/*t->elem==elem*/
}
link insert(link t,unsigned char elem){
	if(!t){
		return make_node(elem);
	}
	if(t->elem>elem){
		t->l=insert(t->l,elem);
	}
	if(t->elem<elem){
		t->r=insert(t->r,elem);
	}
	return t;
}
link delete(link t,unsigned char elem){
	link p;
	if(!t){
		return NULL;
	}
	if(t->elem>elem){
		t->l=delete(t->l,elem);
	}else if(t->elem<elem){
		t->r=delete(t->r,elem);
	}else{
		if(!t->l&&!t->r){
			free_node(t);
			t=NULL;
		}else if(t->l){
			for(p=t->l;p->r;p=p->r);
			t->elem=p->elem;
			t->l=delete(t->l,t->elem);
		}else{
			for(p=t->r;p->l;p=p->l);
			t->elem=p->elem;
			t->r=delete(t->r,t->elem);
		}
	}
	return t;
}
void print_tree(link t){
	if(t){
		printf("(");
		printf("%d",t->elem);
		print_tree(t->l);
		print_tree(t->r);
		printf(")");
	}else{
		printf("()");
	}
}
