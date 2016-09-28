#include<stdio.h>
#define MAX_VERTEX_NUM 20
typedef char VertexType;
typedef struct _ArcNode{
	int adjvex; //the vertex point to
	struct _ArcNode* nextarc;
	//InfoType* info;
}ArcNode,*pArcNode;
typedef struct {
	VertexType data;
	pArcNode firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct{
	AdjList	vertexs;
	int vexnum;
	int arcnum;
	int kind;
}ALGraph;
void createALG(ALGraph* gra){
	int i,j;
	printf("G.vexnum:");
	scanf("%d",&(gra->vexnum));	
	getchar();	//for enter
	for(i=0;i<gra->vexnum;++i){
		printf("G.vertexs[%d].data:",i);
		scanf("%c",&(gra->vertexs[i].data));
		getchar();
		gra->vertexs[i].firstarc=NULL;
	}
	for(i=0;i<gra->vexnum;++i){
		pArcNode p,cur,h;
		printf("please input the adjacent vertex,end by -1:");
		if(scanf("%d",&j),j!=-1){
			h=p=cur=(pArcNode)malloc(sizeof(ArcNode));
			h->adjvex=j;
		}else{
			gra->vertexs[i].firstarc=NULL;
			continue;
		}
		while(scanf("%d",&j),j!=-1){
			p=(pArcNode)malloc(sizeof(ArcNode));
			p->adjvex=j;
			cur->nextarc=p;
			cur=p;
		}
		cur->nextarc=NULL;
		gra->vertexs[i].firstarc=h;
	}
}
void show(ALGraph* gra){
	int i;
	pArcNode cur;
	for(i=0;i<gra->vexnum;++i){
		printf("%c--->",gra->vertexs[i].data);
		cur=gra->vertexs[i].firstarc;
		while(cur){
			printf("%c,",gra->vertexs[cur->adjvex].data);
			cur=cur->nextarc;
		}
		printf("\b\n");
	}
}
int main(){
	ALGraph gra;
	createALG(&gra);
	show(&gra);
	return 0;
}
