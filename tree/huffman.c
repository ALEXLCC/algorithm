/*
 	huffman tree
 */
#include<stdio.h>
#define N 100
typedef struct _arrTree{
	int weight;
	int parent;
	int lchild;
	int rchild;
}arrayTree,*pArrayTree;
typedef struct _tree{
	int data;
	int visit;
	struct _tree *left;
	struct _tree * right;
}tree,*pTree;
void initArray(pArrayTree at,int* len){
	int i=0;
	scanf("%d",len);
	while(scanf("%d",&((at+i)->weight)),++i<*len);
}
void arrayCreate(pArrayTree at,int len){
	int min1,min2,j,k=len;
	if(len<2){
		printf("the tree is so small!\n");
		return;
	}
	for(;k<2*len-1;++k){
		min1=0;
		while(at[min1].parent){
			++min1;
		}
		min2=min1+1;
		while(at[min2].parent){
			++min2;
		}
		for(j=0;j<k;++j){
			if(at[j].parent||j==min1||j==min2){
				continue;
			}		
			if(at[min1].weight>at[min2].weight){
				int t=min1;
				min1=min2;
				min2=t;
			}
			if(at[j].weight<at[min1].weight){
				min2=min1;
				min1=j;
			}else if(at[j].weight<at[min2].weight){
				min2=j;
			}
		}
		at[k].weight=at[min1].weight+at[min2].weight;
		at[k].lchild=min1;
		at[k].rchild=min2;
		at[min1].parent=k;
		at[min2].parent=k;
	}
}
void show(pArrayTree at,int len){
	int i=0;
	printf("weight parent lchild rchild\n");
	for(;i<2*len-1;++i){
		printf("%-7d%-7d%-7d%-7d\n",at[i].weight,at[i].parent,at[i].lchild,at[i].rchild);
		if(i==len-1){
			printf("-----------------\n");
		}
	}
}
int main(){
	int len;
	arrayTree at[2*N-1]={{0,0,0,0}};
	initArray(at,&len);
	arrayCreate(at,len);
	show(at,len);
	return 0;
}
