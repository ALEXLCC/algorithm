#include<stdio.h>
#define MAXSIZE 10000
#define MAXRC 100
typedef struct{
	int i;	//row
	int j;	//col
	int e;	//element
}Triple;
typedef struct{
	Triple data[MAXSIZE+1];
	int rpos[MAXRC+1];	//every row first not zero
	int mu,nu,tu;
}RLSMatrix;
void show(RLSMatrix *rm){
	int k;
	printf("Matrix:\n");
	for(k=1;k<rm->tu+1;++k){
		printf("%d,%d,%d\n",tm->i,tm->j,tm->e);
	}
}
void mutl(RLSMatrix *m,RLSMatrix *n,RLSMatrix *q){
	if(m->nu!=n->mu){
		return;
	}
	q->mu=m->mu;
	q->nu=n->nu;
	q->tu=0;
	if(m->tu*n->tu!=0){
		int ctemp[MAXSIZE]={0};

	}
}
