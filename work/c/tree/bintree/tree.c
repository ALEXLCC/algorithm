/*
 *	binary tree 
 *	author lijinya
 *	2014/7/18
 *
 * *
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct _tree{
	int data;
	struct _tree *left;
	struct _tree *right;
}tree,*pTree;
pTree create(pTree root){
	int data;
	if(scanf("%d",&data),!data){
		root=NULL;
	}else{
		if(!(root=(pTree)malloc(sizeof(tree)))){
			exit(-1);
		}
		root->data=data;
		root->left=create(root->left);
		#ifdef DEBUG
		printf("left->0x%p\n",root->left);
		#endif
		root->right=create(root->right);
		#ifdef DEBUG
		printf("right->0x%p\n",root->right);
		#endif
	}
	return root;
}
void preTravel(pTree root){
	if(root){
		printf("%d ",root->data);
		preTravel(root->left);
		preTravel(root->right);
	}
}
void midTravel(pTree root){
	if(root){
		midTravel(root->left);
		printf("%d ",root->data);
		midTravel(root->right);
	}
}
void postTravel(pTree root){
	if(root){
		postTravel(root->left);
		printf("%d ",root->data);
		postTravel(root->right);
	}
}
int main(){
	tree root;
	pTree proot;
	proot=create(&root);
	postTravel(proot);
	printf("\n");
	return 0;
}
