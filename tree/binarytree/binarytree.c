#include<stdio.h>
#include<stdlib.h>
typedef struct _tree{
	int ch;
	struct _tree* left;
	struct _tree* right;
}tree,*pTree;
pTree create(pTree t){
	char ch;
	scanf("%c",&ch);	
	if('#'==ch){
		t=NULL;
	}else{
		if(!(t=(pTree)malloc(sizeof(tree)))){
			return NULL;
		}
		t->ch=ch;
		#ifdef DEBUG
			printf("ch: %c,t->left:0x%p,t->right:0x%p\n",t->ch,t->left,t->right);
		#endif
		t->left=create(t->left);
		t->right=create(t->right);
	}
	return t;
}
void travel(pTree t){
	if(t){
		printf("%c ",t->ch);
		travel(t->left);
		travel(t->right);
	}
}
int main(){
	pTree root=NULL;
	root=create(root);
	travel(root);
	printf("\n");
	return 0;
}
