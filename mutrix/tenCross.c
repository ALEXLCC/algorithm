#include<stdio.h>
#define MAXSIZE 10000
typedef int ElemType;
typedef struct _OLNode{
	int i,j;
	ElemType e;
	struct _OLNode * right, *down;
}OLNode,*pOLNode;
typedef struct{
	pOLNode *rhead,*chead;//pointer to a address array
	int mu,nu,tu;
}CrossList,*pCrossList;
void CreateSMatrix_OL(pCrossList m){
	int i,j,e;
//	if(m)	m=NULL;
	scanf("%d%d%d",&m->mu,&m->nu,&m->tu);
	if(!(m->rhead=(pOLNode*)malloc((m->mu+1)*sizeof(pOLNode)))){
		printf("memory allocate failed!\n");
		//return;
		exit(-1);
	}
	if(!(m->chead=(pOLNode*)malloc((m->nu+1)*sizeof(pOLNode)))){
		printf("memory allocate failed!\n");
		//return;
		exit(-1);
	}
	for(i=0;i<m->mu+1;++i){
		m->rhead[i]=NULL;
	}
	for(i=0;i<m->nu+1;++i){
		m->chead[i]=NULL;
	}
	for(scanf("%d%d%d",&i,&j,&e);i!=0;scanf("%d%d%d",&i,&j,&e)){
		pOLNode p;
		if(!(p=(pOLNode)malloc(sizeof (OLNode)))){
			printf("memory allocate failed!\n");
			exit(-1);
		}
		p->i=i;
		p->j=j;
		p->e=e;
		if(!m->rhead[i]){
			m->rhead[i]=p;
		}else{
			pOLNode q;
			for( q=m->rhead[i];(q->right)&&q->right->j<j;q->right){
			p->right=q->right;
			}
		q->right=p;
		}
		if(!m->chead[j]){
			m->chead[j]=p;
		}else{
			pOLNode q;
			for(q=m->chead[j];(q->down)&&q->down->i<i;q->down){
			p->down=q->down;
			}
		q->down=p;
		}
	}
}
void show(pCrossList cl){
	int i;
	for(i=1;i<cl->mu+1;++i){
		pOLNode h=cl->rhead[i];
		while(h){
			printf("%d,%d,%d\n",h->i,h->j,h->e);
			h=h->right;
		}
	}
}
int main(){
	pCrossList m=(pCrossList)malloc(sizeof (CrossList));
	CreateSMatrix_OL(m);
	show(m);
	return 0;
}
