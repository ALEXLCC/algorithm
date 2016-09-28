#include<stdio.h>
#define MAXSIZE 10000
#define MAX 100
typedef int ElemType;
typedef struct{
	int i;
	int j;
	ElemType e;
}Triple;
typedef union{
	Triple data[MAXSIZE+1];
	int mu;		//rows
	int nu;		//cols
	int tu;		///element counts not zero
}TSMatrix;
void TransposeSMatrix(TSMatrix m,TSMatrix* t){
	int p,q=1,col;
	int num[MAX]={0};
	int cpot[MAX]={0};
	t->mu=m.mu;
	t->nu=m.nu;
	t->tu=m.tu;
	cpot[1]=1;
	if(t->tu){
		for(p=1;p<=m.tu;++p){
			++num[m.data[p].j];
		}
		for(p=2;p<=m.nu;++p){
			cpot[p]+=cpot[p-1]+num[p-1];
		}
		for(col=1,p=1;p<=m.tu;++p){
				col=m.data[p].j;
				q=cpot[col];
				t->data[q].i=m.data[p].j;
				t->data[q].j=m.data[p].i;
				t->data[q].e=m.data[p].e;
				++cpot[col];
		}
	}
}
void show(TSMatrix *t){
	int k;
	for(k=1;k<=t->tu;++k){
		printf("item: %d,%d,%d\n",t->data[k].i,t->data[k].j,t->data[k].e);
	}
}
void init(TSMatrix *t){
	int k;
	for(k=1;k<=t->tu;++k){
		scanf("%d,%d,%d",&t->data[k].i,&t->data[k].j,&t->data[k].e);
	}
}
int main(){
	TSMatrix t,m;
	m.mu=6;
	m.nu=6;
	m.tu=8;
/*	m.data[MAXSIZE+1]={
				{6,6,8}
				,
				m.data[1]={1,2,12};
				m.data[2]={1,3,9};
				m.data[3]={3,1,-3};
				{3,6,14},
				{4,3,24},
				{5,2,18},
				{6,1,15},
				{6,4,-7}	
				};	*/
	init(&m);
	printf("Before transpose matrix:\n");
	show(&m);
	TransposeSMatrix(m,&t);
	printf("After transpose matrix:\n");
	show(&t);
	return 0;
}
