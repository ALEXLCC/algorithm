#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
typedef struct node* link;
typedef struct node{
	int item;
	link l,r;
}node;
link NODE(int item,link l,link r){
	link t=malloc(sizeof *t);
	t->item=item;
	t->l=l;
	t->r=r;
	return t;
}
link insert_node(link t,int item){
	if(NULL==t){
		return NODE(item,NULL,0);
	}
	if(item<t->item){
		t->l=insert_node(t->l,item);
	}
	if(item>t->item){
		t->r=insert_node(t->r,item);
	}
	return t;
}
void pprint(link root){
	printf("(");	
	if(root){
		printf("%d",root->item);	
		pprint(root->l);
		pprint(root->r);
	}
	printf(")");	
}
int bst_search(link t,int item){
	if(!t){
		return 0;
	}
	if(item<t->item){
		return bst_search(t->l,item);
	}else if(item>t->item){
		return bst_search(t->r,item);
	}else{
		return 1;
	}
}
int main(){
	int i;
	link root=NULL;
	srand(time(0));
	for(i=0;i<N;++i){
		root=insert_node(root,rand()%100);
	}
	printf("\t\\tree");
	pprint(root);
	printf("\n");
	printf("%d\n",bst_search(root,50));
	return 0;
}
