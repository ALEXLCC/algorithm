#include<stdio.h>
#include<stdlib.h>
#define TAG 1
typedef struct _tree{
	int data;
	struct _tree* left;
	int ltag;	//if left child is NULL ,1
	struct _tree* right;
	int rtag;	//
}tree,*pTree;
pTree create(pTree root){
	int da;
	if(scanf("%d",&da),da){
		pTree p;
		if(!(p=(pTree)malloc(sizeof(tree)))){
			exit(-1);
		}
		p->data=da;
		p->ltag=p->rtag=0;
		p->left=create(p->left);
		p->right=create(p->right);
		return p;
	}else{
		return NULL;
	}
}
void traverse(pTree root){
	if(root){
		printf("%d ",root->data);
		traverse(root->left);
		traverse(root->right);
	}
}
void threadTraverse(pTree root,pTree* pprev){
	if(root){
		if(root->left&&!root->ltag){
			*pprev=root;
			threadTraverse(root->left,pprev);
		}
		if(!root->left){
			root->ltag=TAG;
			root->left=*pprev;	
		}
		if(!(*pprev)->right){
			(*pprev)->rtag=TAG;
			(*pprev)->right=root;
		}
//	*pprev=root;
		if(!root->right){
			*pprev=root;
			while((*pprev)->rtag){
				(*pprev)=(*pprev)->left;
			}
		}
		threadTraverse(root->right,pprev);
	}
}
void thread(pTree phead,pTree root){
	pTree* pprev=(pTree*)malloc(sizeof(pTree));
	if(!root){
		phead->left=phead;
	}else{
		phead->left=root;
		*pprev=phead;
		threadTraverse(root,pprev);
		(*pprev)->right=phead;
		(*pprev)->rtag=1;
		phead->right=*pprev;
		phead->rtag=1;
	}
}
void Travel(pTree phead){
	pTree p=phead->left;
		printf("left=0x%p,addr=0x%p,next=0x%p\n",phead->left,phead,phead->right);
	while(p!=phead){
		while(!p->ltag){
		printf("addr=0x%p,data=%d,ltag=%d,rtag=%d next=0x%p\n",p,p->data,p->ltag,p->rtag,p->right);
			p=p->left;
		}
		while(p->rtag&&p->right!=phead){
			p=p->right;
		printf("addr=0x%p,data=%d,ltag=%d,rtag=%d next=0x%p\n",p,p->data,p->ltag,p->rtag,p->right);
		}
		p=p->right;
	}
}
int main(){
	pTree root;
	pTree phead=(pTree)malloc(sizeof(tree));
	root=create(root);
//	traverse(root);
	thread(phead,root);
	Travel(phead);
	return 0;
}
