#include<stdio.h>
#include<stdlib.h>
#define N 100
#define RED 1
#define BLACK 0
typedef struct node{
	int elem;
	int color;	//1 red 0 black
	struct node* parent;
	struct node* lchild;
	struct node* rchild;
}tree,*pTree;
pTree null;
void RBNODE(){
	null=malloc(sizeof *null);
	null->elem=0;
	null->color=BLACK;
	null->lchild=null;
	null->rchild=null;
	null->parent=null;
}
pTree NODE(pTree t,int elem){
	t=malloc(sizeof *t);
	t->elem=elem;
	t->lchild=null;
	t->rchild=null;
	t->parent=null;
	return t;
}
void left_rotate(pTree* root,pTree *x){
	pTree y=(*x)->rchild;
	(*x)->rchild=y->lchild;
	if(y->lchild!=null){
		y->lchild->parent=*x;
	}
	y->parent=(*x)->parent;
	if((*x)->parent==null){
		*root=y;
	}else if((*x)==(*x)->parent->lchild){
		(*x)->parent->lchild=y;
	}else{
		(*x)->parent->rchild=y;
	}
	y->lchild=*x;
	(*x)->parent=y;
}
void right_rotate(pTree* root,pTree *y){
	pTree x=(*y)->lchild;
	(*y)->lchild=x->rchild;
	if(x->rchild!=null){
		x->rchild->parent=*y;
	}
	x->parent=(*y)->parent;
	if((*y)->parent==null){
		*root=x;
	}else if(x==x->parent->rchild){
		x->parent->rchild=x;
	}else{
		x->parent->lchild=x;
	}
	x->rchild=*y;
	(*y)->parent=x;
}
void rb_insert_fixup(pTree *root,pTree *z){
	pTree y;
	while(RED==(*z)->parent->color){
		if((*z)->parent==(*z)->parent->parent->lchild){
			y=(*z)->parent->parent->rchild;
			if(y->color==RED){
				(*z)->parent->color=BLACK;
				y->color=BLACK;
				(*z)->parent->parent->color=RED;
				(*z)=(*z)->parent->parent;
			}else if(*z==(*z)->parent->rchild){
				*z=(*z)->parent;
				left_rotate(root,z);
			}
			(*z)->parent->color=BLACK;
			(*z)->parent->parent->color=RED;
			right_rotate(root,&(*z)->parent->parent);
		}else{
			y=(*z)->parent->parent->lchild;
			if(y->color==RED){
				(*z)->parent->color=BLACK;
				y->color=BLACK;
				(*z)->parent->parent->color=RED;
				(*z)=(*z)->parent->parent;
			}else if(*z==(*z)->parent->lchild){
				*z=(*z)->parent;
				right_rotate(root,z);
			}
			(*z)->parent->color=BLACK;
			(*z)->parent->parent->color=RED;
			left_rotate(root,&(*z)->parent->parent);
		}
	}
	(*root)->color=BLACK;
}
void rb_insert(pTree *root,pTree *z){
	pTree y=null;	//save the parent
	pTree x=*root;
	while(x!=null){
		y=x;
		if((*z)->elem<x->elem){
			x=x->lchild;
		}else{
			x=x->rchild;
		}
	}
	(*z)->parent=y;
	if(y==null){
		*root=*z;
	}else if((*z)->elem<y->elem){
		y->lchild=*z;
	}else{
		y->rchild=*z;
	}
	(*z)->color=RED;
	rb_insert_fixup(root,z);
}
void show(pTree root){
	if(root!=null){
		printf("%d%c\n",root->elem,root->elem==RED?'+':'-');
		show(root->lchild);
		show(root->rchild);
	}
}
int main(){
	pTree root,node;
	int i,len;
//	int array[N]={11,2,14,15,1,7,5,8,4};
	int array[N]={41,38,31,12,19,8};
	RBNODE();
	root=null;
	len=6;
	for(i=0;i<len;++i){
		node=NODE(node,array[i]);
		rb_insert(&root,&node);
	}
	show(root);
	return 0;
}
