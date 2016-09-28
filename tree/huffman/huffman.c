/*
 	huffman tree
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
	char code[256];
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
	printf("index weight parent lchild rchild\n");
	for(;i<2*len-1;++i){
		printf("%-7d%-7d%-7d%-7d%-7d\n",i,at[i].weight,at[i].parent,at[i].lchild,at[i].rchild);
		if(i==len-1){
			printf("---------------------------------------\n");
		}
	}
}
pTree createTree(pTree root,pArrayTree at,int len){
	int i=2*len-2;
	root=(pTree)malloc(sizeof(tree)*(2*len-1));
	while(i>=0){
		root[i].data=at[i].weight;
		if(at[i].lchild){
			root[i].left=root+at[i].lchild;
			root[i].right=root+at[i].rchild;
		}else{
			root[i].left=NULL;
			root[i].right=NULL;
		}
		--i;
	}
	return root+2*len-2;
}
void traverse(pTree root,char* str){
	if(root){
		char st[256]="";
		printf("%-5d ",root->data);
		strcpy(root->code,str);
		printf("%s\n",root->code);
		strcpy(st,root->code);
		traverse(root->left,strcat(st,"0"));
		st[strlen(st)-1]='1';
		st[strlen(st)]=0;
		traverse(root->right,st);
	}
}
/*
 	show the code
 */
void showCode(pTree root){
	if(root){
		if(!root->left&&!root->right){
			printf("%-5d %s\n",root->data,root->code);
		}
		showCode(root->left);
		showCode(root->right);
	}
}
void initCodes(char (*codes)[256],int len,pTree root){
	int i=0;
	for(;i<len;++i){
		strcpy(codes[i],(root-2*len+2+i)->code);
	}
}
void showInitCode(char (*codes)[256],int len){
	int i=0;
	for(;i<len;++i){
		printf("      %s\n",codes[i]);
	}
}
void decode(char (*codes)[256],int len,const char* str){
	char* ps=str;
	char res[1024]="";
	int num[N]={0},i;
	for(i=0;i<len;++i){
		num[i]=strlen(codes[i]+1);
	}
	while(*ps){
		for(i=0;i<len;++i){
			char ss[256]="";
			strncpy(ss,ps,num[i]);
			if(!strcmp(ss,codes[i]+1)){
				printf("%d",i);	//此处用于调试输出。
//				strcat(res,itoa(i,ss,10));
				sprintf(ss,"%d",i);
				strcat(res,ss);
				ps+=num[i];
				break;
			}
		}
	}
	printf("\n%s\n",res);
}
int main(){
	int len;
	char codes[N][256];
	char source[1024];
	pTree root;
	arrayTree at[2*N-1]={{0,0,0,0}};
	initArray(at,&len);
	arrayCreate(at,len);
	show(at,len);
	printf("\n");
	root=createTree(root,at,len);
	traverse(root,"#");
	printf("\n");
	showCode(root);
	initCodes(codes,len,root);
	showInitCode(codes,len);
	getchar();
	gets(source);
	decode(codes,len,source);
	return 0;
}
