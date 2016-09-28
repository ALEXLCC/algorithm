#include<stdio.h>
#include<limits.h>
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20	//max vertex number
typedef char VertexType;
typedef char* InfoType;
typedef enum{DG,DN,AG,AN}GraphiKind;
typedef struct _ArcCell{
	VertexType adj;	//
/*	typedef struct{
		struct _ArcCell* start;
		struct _ArcCell* end;
		//InfoType * info;
	} *info;*/
//	struct _ArcCell* info;
//	int info;	//0---->   1 <-----
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum,arcnum;
	GraphiKind kind;
}MGraph;
int locateVertex(MGraph* gra,VertexType v){
	int i;
	for(i=0;i<gra->vexnum;++i){
		if(gra->vexs[i]==v){
			return i;
		}
	}
	return -1;
}
void createDG(MGraph* gra){
	int i,j,k;
	VertexType v1,v2;
	printf("please input the vertex number:");
	scanf("%d",&(gra->vexnum));
	printf("please input the arcCell number:");
	scanf("%d",&(gra->arcnum));
	getchar();	//take in the enter
	for(i=0;i<gra->vexnum;++i){
		printf("G.vexs[%d]:",i);
		scanf("%c",&(gra->vexs[i]));
		getchar();
	}
	for(i=0;i<gra->vexnum;++i){
		for(j=0;j<gra->vexnum;++j){
			gra->arcs[i][j].adj=0;
//			gra->arcs[i][j].info=NULL;
		}
	}
	for(i=0;i<gra->arcnum;++i){
		printf("v1(char):");
		scanf("%c",&v1);
		getchar();
		printf("v2(char):");
		scanf("%c",&v2);
		getchar();
		j=locateVertex(gra,v1);
		k=locateVertex(gra,v2);
		gra->arcs[j][k].adj=1;
//		gra->arcs[i][j].info=0;	
	}
}
void show(MGraph* gra){
	int i,j;
	for(i=0;i<gra->vexnum;++i){
		for(j=0;j<gra->vexnum;++j){
			printf("%d ",gra->arcs[i][j].adj);
		}
		printf("\n");
	}
}
int main(){
	MGraph gra;
	createDG(&gra);
	show(&gra);
	return 0;
}
