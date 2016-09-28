#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 100
typedef char ElementType;
typedef struct _BiTree{
	ElementType data;
	struct _BiTree* left;
	struct _BiTree* right;
}BiTree,*pBiTree;
typedef struct{
	ElementType elems[N];
	int weights[N];
	int length;
}SSTable,*pSSTable;
pBiTree secondOptimal(pBiTree root,ElementType *r,float* sw,int low,int high){
		float min=fabs(sw[high]-sw[low]);
		float dw=sw[high]+sw[low-1];
		int i=low,j;
		for(j=i+1;j<=high;++j){
			if(fabs(dw-sw[j]-sw[j-1])<min){
				i=j;
				min=fabs(dw-sw[j]-sw[j-1]);
			}
		}
		if(!(root=(pBiTree)malloc(sizeof(BiTree)))){
			exit(-1);
		}
		root->data=r[i];
		if(i==low){
			root->left=NULL;
		}else{
			root->left=secondOptimal(root->left,r,sw,low,i-1);
		}
		if(i==high){
			root->right=NULL;
		}else{
			root->right=secondOptimal(root->right,r,sw,i+1,high);
		}
		return root;
}
void findSW(float *sw,pSSTable st){
	int i;
	sw[-1]=0;
	for(i=0;i<st->length;++i){
		sw[i]=sw[i-1]+st->weights[i];
	}
}
typedef BiTree SOSTree;
pBiTree createSosTree(SOSTree* root,pSSTable st){
	if(!st->length){
		root=NULL;
	}else{
//		float sw[st->length];
		float sw[N]={0.0f};
		sw[-1]=0.0f;
		findSW(sw,st);
		root=secondOptimal(root,st->elems,sw,0,st->length-1);
		return root;
	}
	return NULL;
}
void init(pSSTable st){
	printf("Init the SSTable:\ninput the length:");
	if(scanf("%d",&st->length),st->length){
		int i;
		getchar();
		for(i=0;i<st->length;++i){
			scanf("%c",&st->elems[i]);
			getchar();
			scanf("%d",&st->weights[i]);
			getchar();
		}
	}
}
void traverse(pBiTree root){
	if(root){
		printf("%c ",root->data);
		traverse(root->left);
		traverse(root->right);
	}
}
int main(){
	pBiTree root;
	pSSTable st=(pSSTable)malloc(sizeof(SSTable));
	init(st);
	root=createSosTree(root,st);
	traverse(root);
	getchar();
	return 0;
}
