/*
 minimun cost spanning tree
 prim algorithm
 */
#include<stdio.h>
#define MAX_VERTEX_NUM 20
#include<limits.h>
typedef int VRType;
typedef char VertexType;
typedef struct{
	VRType adj;
}ArcCell,AdjMutrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMutrix arcs;
	int vexnum,arcnum;
}MGraph,*pMGraph;
typedef struct{
	VertexType data;
	int next;
}minlen,*pMinlen;
int locateVertex(pMGraph gra,VertexType ch){
	int i;
	for(i=0;i<gra->vexnum;++i){
		if(ch==gra->vexs[i]){
			return i;
		}
	}
	return -1;
}
void createMG(pMGraph gra){
	int i,j,k;
	char v1,v2;
	printf("create MGraph:\nvexnum  and arcnum:");
	scanf("%d%d",&(gra->vexnum),&(gra->arcnum));
	getchar();
	printf("please input the vertexs:separated by space,end by enter:");
	for(i=0;i<gra->vexnum;++i){
		scanf("%c",gra->vexs+i);
		getchar();
	}
	for(i=0;i<gra->vexnum;++i){
		for(j=0;j<gra->vexnum;++j){
			gra->arcs[i][j].adj=INT_MAX;
		}
	}
	printf("please input the arcs:\nv1(char),v2(char),power(int):");
	for(i=0;i<gra->arcnum;++i){
		scanf("%c",&v1);
		getchar();
		j=locateVertex(gra,v1);
		scanf("%c",&v2);
		getchar();
		k=locateVertex(gra,v2);
		scanf("%d",&(gra->arcs[j][k].adj));
		gra->arcs[k][j].adj=gra->arcs[j][k].adj;
		getchar();
	}
}
void show(pMGraph gra){
	int i,j;
	for(i=0;i<gra->vexnum;++i){
		printf("%c\t",gra->vexs[i]);
		for(j=0;j<gra->vexnum;++j){
			printf("%d ",gra->arcs[i][j].adj<INT_MAX?gra->arcs[i][j].adj:-1);
		}
		printf("\n");
	}
}
minlen find_min(pMGraph gra,int* close){
	int i,j,min=INT_MAX;
	minlen ml;
	for(i=0;i<gra->vexnum;++i){
		if(close[i]){
			for(j=0;j<gra->vexnum;++j){
				if(j!=i&&!close[j]&&gra->arcs[i][j].adj<min){
					min=gra->arcs[i][j].adj;
					ml.next=j;
					ml.data=gra->vexs[i];
				}
			}
		}
	}
	return ml;
}
void prim(pMGraph gra,int v){
	int i,j;
	minlen ml;
	int close[MAX_VERTEX_NUM]={0};
	close[v]=1;
	ml=find_min(gra,close);
	for(i=0;i<gra->vexnum-1;++i){
		if(INT_MAX==ml.next){
			return ;
		}
		printf("%c--%d--%c\n",ml.data,gra->arcs[locateVertex(gra,ml.data)][ml.next].adj,gra->vexs[ml.next]);
		close[ml.next]=1;
		ml=find_min(gra,close);
	}
}
int main(){
	MGraph gra;
	createMG(&gra);
	show(&gra);
	prim(&gra,3);
	return 0;
}
