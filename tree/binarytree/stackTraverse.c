#include<stdio.h>
typedef struct _tree{
	int data;
	int visit;
	struct _tree* left,*right,*parent,*next;
}tree,*pTree;
typedef struct _tStack{
	pTree top;
	pTree bottom;
}tStack,*ptStack;
pTree getTop(ptStack psta){
	return psta->top;
}
void push(ptStack psta,pTree t){
	t->next=psta->top;
	psta->top=t;
}
pTree pop(ptStack psta){
	pTree pt=psta->top;
	pTree t=pt;
	psta->top=psta->top->next;
//	free(pt);
	return t;
}
void init(ptStack psta){
	psta->top=psta->bottom=NULL;
}
int empty(ptStack psta){
	return psta->top==psta->bottom;
}
pTree create(pTree root){
	int da;
	pTree t;
	if(scanf("%d",&da),da){
		if(!(t=(pTree)malloc(sizeof(tree)))){
			exit(-1);
		}
		t->data=da;
		t->visit=0;
		t->left=create(t->left);
		t->right=create(t->right);
	}else{
		return NULL;
	}
	return t;
}
void traverse(pTree root){
	if(root){
		traverse(root->left);
		printf("%d ",root->data);
		traverse(root->right);
	}
}
void inOrder(pTree root,ptStack psta){
	pTree pt=root;
	push(psta,pt);
	while(!empty(psta)){
		while((pt=getTop(psta))&&(pt->left)&&(!pt->left->visit)){
			push(psta,pt->left);
		}
		if(!empty(psta)){
			pt=pop(psta);
			printf("%d ",pt->data);
			pt->visit=1;
			if(pt->right&&!pt->right->visit){
					push(psta,pt->right);
			}
		}
	}
}
void inOrder_2(pTree root,ptStack psta){
	pTree pt=root;
	while(pt||!empty(psta)){
		if(pt&&!pt->visit){
			push(psta,pt);
			pt=pt->left;
		}else{
			pt=pop(psta);
			printf("%d ",pt->data);
			pt->visit=1;
/*			if(pt->right&&!pt->right->visit){
					push(psta,pt->right);
			}
			*/
			pt=pt->right;
		}
	}
}
int main(){
	ptStack psta=(ptStack)malloc(sizeof(tStack));
	pTree root=NULL;
	pTree t1=(pTree)malloc(sizeof(tree));
//	tree t1,t2;
	t1->data=9;
	pTree t2=(pTree)malloc(sizeof(tree));
	t2->data=7;
	init(psta);
	push(psta,t1);
	push(psta,t2);
	printf("%d   %d  \n",pop(psta)->data,pop(psta)->data);
	if(!empty(psta)){
		return 0;
	}
	root=create(root);
	traverse(root);
	printf("\n");
//	inOrder(root,psta);
	printf("\n");
	inOrder_2(root,psta);
	printf("\n");
	free(psta);
	return 0;
}
