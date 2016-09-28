#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _tree{
	int type;
//	union
	double val;
	char op;
	struct _tree* left;
	struct _tree* right;
}Tree,*pTree;
int find(int s,int t,const char* strs){
	int i=-1,flag=0,pri=3;
	if('('==strs[s]&&')'==strs[t]){
		if(s+1==t){
			return -2;
		}
		s+=1;
		t-=1;
	}
	while(t>=s){
		if(')'==strs[t]){
			--flag;
		}else if('('==strs[t]){
			++flag;
		}else if(!flag&&('*'==strs[t]||'/'==strs[t])&&pri>2){
			i=t;
			pri=2;
		}else if(!flag&&('+'==strs[t]||'-'==strs[t])){
			return t;
		}
		--t;
	}
	return i;
}
double todouble(char* str,int s,int t){
	double d=0.0,df=0.0;
	int point;
	while(s<=t){
		if('.'==str[s]){
			point=1;
			break;
		}
		d=d*10+str[s]-'0';
		++s;
	}
	s+=1;
	while(s<=t){
		df=df/10+str[t]-'0';
		--t;
	}
	df/=10;
	return d+=df;
}
double cal(double a,char o,double b){
	switch(o){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
		 	return a/b;
	}
	return 0.0;
}
pTree Create(char*str,int s,int t){
	int r=find(s,t,str);
	pTree root;
	if(-2==r){
		root=(pTree)malloc(sizeof(Tree));
		root->op='#';
		root->val=0.0;
		root->left=NULL;
		root->right=NULL;
//		return NULL;
	}else if(-1==r){
		root=(pTree)malloc(sizeof(Tree));
		root->op='#';
		root->val=todouble(str,s,t);
		root->left=NULL;
		root->right=NULL;
	//	return root;
	}else{
		if('('==str[s]&&')'==str[t]){
			s+=1;
			t-=1;
		}else{
			root=(pTree)malloc(sizeof(Tree));
			root->op=str[r];
			root->val=0.0;
			root->left=Create(str,s,r-1);
			root->right=Create(str,r+1,t);
		}
	}
	return root;
}
void travel(pTree root){
	if(root){
		travel(root->left);
		printf("root:0x%p,left:0x%p,right:0x%p,type=%d,val=%lf,op=%c\n",root,root->left,root->right,root->type,root->val,root->op);
		travel(root->right);
	}
}
void CalculateTree(pTree root){
	if(root){
		CalculateTree(root->left);
		CalculateTree(root->right);
		if(root->left!=NULL&&'#'==root->left->op&&'#'==root->left->op){
			root->val=cal(root->left->val,root->op,root->right->val);
			free(root->left);
			free(root->right);
			root->left=NULL;
			root->right=NULL;
			root->op='#';
		}
	}
}
int main(){
	char str[128];
//	int i=find(0,strlen(str)-1,gets(str));
	int len;
	pTree root;
	gets(str);
	len=strlen(str);
	root=Create(str,0,len-1);
	travel(root);
	CalculateTree(root);
	printf("%lf\n",root->val);
//	printf("%d\n",i);
	return 0;
}
