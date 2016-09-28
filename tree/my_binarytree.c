#include<stdio.h>
#include<stdlib.h>

typedef struct _tree{
	int ch;
	struct _tree* left;
	struct _tree* right;
}tree,*pTree;
pTree create(pTree t){
	int ch;
	scanf("%d",&ch);
	if(0==ch){
		t=NULL;
	}else{
		if(!(t=(pTree)malloc(sizeof(tree)))){
			return 0;
		}
		t->ch=ch;
		#ifdef DEBUG
			printf("ch: %d,t->left:0x%p,t->right:0x%p\n",t->ch,t->left,t->right);
		#endif
		t->left=create(t->left);
		t->right=create(t->right);
	}
	return t;
}
void travel(pTree t){
	if(t){
		printf("%d ",t->ch);
		travel(t->left);
		travel(t->right);
	}
}
int main(){
	pTree root=(pTree)malloc(sizeof (tree));
	root=create(root);
	#ifdef DEBUG
        printf("ch:%d,root->left:0x%p,root->right:0x%p\n",
               root->ch,root->left,root->right);
	#endif // DEBUG
	travel(root);
	getchar();
	return 0;
}
