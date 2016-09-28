#include<stdio.h>
#include<stdlib.h>
typedef struct _tree{
	int data;
	struct _tree* lchild;
	struct _tree* rchild;
}Tree,*pTree;
int searchBSD(pTree root,int key,pTree f,pTree *p){
	if(!root){
		*p=f;
		return 0;
	}else if(key==root->data){
		*p=root;
		return 1;
	}else if(key<root->data){
		searchBSD(root->lchild,key,root,p);
	}else{
		searchBSD(root->rchild,key,root,p);
	}
}
pTree insertBSD(pTree root,int e){
	pTree *p=(pTree*)malloc(sizeof(pTree)),s;
	if(!searchBSD(root,e,NULL,p)){
		if(!(s=(pTree)malloc(sizeof(Tree)))){
			exit(-1);
		}
		s->data=e;
		s->lchild=s->rchild=NULL;
		if(!*p){
			root=s;
		}else if(e<(*p)->data){
			(*p)->lchild=s;
		}else{
			(*p)->rchild=s;
		}
	}
	free(p);
	return root;
}
void show(pTree root){
	if(root){
		printf("%d ",root->data);
		show(root->lchild);
		show(root->rchild);
	}
}
void delete(pTree *root){
	if(!(*root)->rchild){
		pTree q=*root;
		*root=(*root)->lchild;
		free(q);
	}else if(!(*root)->lchild){
		pTree q=*root;
		*root=(*root)->rchild;
		free(q);
	}else{
		pTree q=*root,s=(*root)->lchild;
		while(s->rchild){
			q=s;
			s=s->rchild;
		}
		(*root)->data=s->data;
		if(q!=*root){
			q->rchild=s->lchild;
		}else{
			q->lchild=s->lchild;
		}
	}
}
void deleteBSD(pTree *root,int key){
	if(!*root){
		return;
	}else{
		if((*root)->data==key){
			delete(root);
		}else if((*root)->data>key){
			deleteBSD(&(*root)->lchild,key);
		}else{
			deleteBSD(&(*root)->rchild,key);
		}
	}
}
int main(){
	int source[]={100,70,110,60,90,80,105,102,120,115},i;
	pTree root=NULL,*p;
	for(i=0;i<10;++i){
		root=insertBSD(root,source[i]);
	}
	show(root);
	printf("\n");
	deleteBSD(&root,110);
	show(root);
	printf("\n");
	return 0;
}
