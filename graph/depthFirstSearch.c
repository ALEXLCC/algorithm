/*
 depth first search
 */
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20
typedef char VRType;
typedef struct{
	VRType data;
	int Near[MAX_VERTEX_NUM];
}Vertex,*pVertex;
typedef struct{
	Vertex nlist[MAX_VERTEX_NUM];
	int arcnum;
	int vexnum;
}MGraph,*pMGraph;
typedef struct{
	pVertex front,rear;
}queue,*pQueue;
void init(pQueue pque){
	pque->front=pque->rear=(pVertex)malloc(sizeof(Vertex)*MAX_VERTEX_NUM);
}
void push(pQueue pque,Vertex v){
	*++pque->rear=v;
}
Vertex pop(pQueue pque){
	return *++pque->front;
}
int empty(pQueue pque){
	return pque->front==pque->rear;
}
Vertex getFront(pQueue pque){
	return *pque->front;
}
Vertex getRear(pQueue pque){
	return *pque->rear;
}
int locateVertex(MGraph* gra,VRType data){
	int i;
	for(i=0;i<gra->vexnum;++i){
		if(data==gra->nlist[i].data){
			return i;
		}
	}
	return -1;
}
void createMGraph(MGraph* gra){
	int i,j,k,power;
	char v1,v2;
	printf("create MGraph:\nvexnum:");
	scanf("%d",&(gra->vexnum));
	printf("arcnum:");
	scanf("%d",&(gra->arcnum));
	getchar();
	for(i=0;i<gra->vexnum;++i){
		printf("nlist[%d].data:",i);
		scanf("%c",&(gra->nlist[i].data));
		getchar();
		for(j=0;j<gra->vexnum;++j){
			gra->nlist[i].Near[j]=INT_MAX;
		}
	}
	for(k=0;k<gra->arcnum;++k){
		printf("v1(char):");
		scanf("%c",&v1);
		getchar();
		printf("v2(char):");
		scanf("%c",&v2);
		getchar();
		i=locateVertex(gra,v1);
		j=locateVertex(gra,v2);
		if(-1==i||-1==j){
			printf("input error!\n");
			exit(-1);
		}
		printf("input the power(int):");
		scanf("%d",&power);
		getchar();
		gra->nlist[i].Near[j]=power;
	}
}
void show(MGraph* gra){
	int i,j;
	for(i=0;i<gra->vexnum;++i){
		printf("%c  ",gra->nlist[i].data);
		for(j=0;j<gra->vexnum;++j){
			printf("%d  ",INT_MAX==gra->nlist[i].Near[j]?-1:gra->nlist[i].Near[j]);
		}
			printf("\n");
	}
}
int getNextVertex(MGraph* gra,int w,int* visit){
	int j;
	for(j=0;j<gra->vexnum;++j){
		if(j!=w&&gra->nlist[w].Near[j]<INT_MAX&&!visit[j]){
			return j;
		}
	}
	return -1;
}
void dfs(MGraph* gra,int v,int* visit){
	int w;
	visit[v]=1;
	printf("%c",gra->nlist[v].data);
	for(w=v;w!=-1;w=getNextVertex(gra,w,visit)){
		if(!visit[w])
			dfs(gra,w,visit);
	}
}
void depthSearch(MGraph* gra){
	int i;
	int visit[MAX_VERTEX_NUM]={0};
	for(i=0;i<gra->vexnum;++i){
		if(!visit[i])
			dfs(gra,i,visit);
	}
}
void breadthSearch(MGraph* gra){
	pQueue pque=(pQueue)malloc(sizeof(queue));
	int i=0,j=0;
	Vertex cur;
	int visit[MAX_VERTEX_NUM]={0};
	init(pque);
	push(pque,gra->nlist[0]);
	visit[0]=1;
	while(!empty(pque)){
		while((i=getNextVertex(gra,j,visit))!=-1&&!visit[i]){
			visit[i]=1;
			push(pque,gra->nlist[i]);
		}
		j=locateVertex(gra,getFront(pque).data);		
		cur=pop(pque);
		printf("%c ",cur.data);
	}
}
int main(){
	MGraph gra;
	createMGraph(&gra);
	show(&gra);
	depthSearch(&gra);
	printf("\n");
	breadthSearch(&gra);
	printf("\n");
	return 0;
}
