#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
typedef struct node* link;
typedef struct node{
	int item;
	int red;
	link l,r;
}node;
link null;
link NODE(int item,link l,link r,int red){
	link t=malloc(sizeof *t);
	t->item=item;
	t->red=red;
	t->l=l;
	t->r=r;
	return t;
}
/*
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
*/
link insert_node(link t,int item,int sw){
	if(t==null){
		return NODE(item,null,null,1);
	}
	if(t->l->red&&t->r->red){
		t->l->red=0;
		t->r->red=0;
		t->red=1;
	}
	if()
}
link RBinsert(link root,int item){
	root=insert_node(root,item,0);
	root->red=0;
	return t;
}
void pprint(link root){
	printf("(");	
	if(root!=null){
		printf("%d,%c",root->item,t->red?'+':'-');	
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
link RBinit(){
	null=NODE(0,NULL,NULL,0);
	null->l=null;
	null->r=null;
	return null;
}
int main(){
	int i;
	link root=NULL;
	srand(time(0));
	root=RBinit();
	for(i=0;i<N;++i){
		root=RBinsert(root,rand()%100);
	}
	printf("\\tree");
	pprint(root);
	printf("\n");
	return 0;
}
