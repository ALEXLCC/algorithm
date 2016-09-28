#include<stdio.h>
#include<stdlib.h>
#define N 100
#define LH 1	/* left high*/
#define EH 0
#define RH -1
typedef struct _BSTNode{
	int data;
	int bf;		//
	struct _BSTNode* lchild,* rchild;
}BSTNode,*pBSDNode;
void R_Rotate(pBSTNode p){
	pBSTNode lc=(*p)->rchild;
	(*p)->lchild=lc->rchild;
	lc->rchild=*p;
	*p=lc;
}
void L_Rotate(pBSTNode* p){
	pBSTNode rc=(*p)->rchild;
	(*p)->rchild=rc->lchild;
	rc->lchild=*p;
	*p=rc;
}
