/*
 tailvex  headvex  hlink tlink info
 data firstin firstout
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20
typedef char VertexType;
typedef struct _ArcBox{
	int tailvex;
	int headvex;
	struct _ArcBox *hlink,*tlink;
	//InfoType* info;
}ArcBox,*pArcBox;
typedef struct{
	VertexType data;
	pArcBox firstin,firstout;
}VexNode;
typedef struct{
	VexNode xlist[MAX_VERTEX_NUM];
	int vexnum,arcnum;
}OLGraph;
int LocateVertex(OLGraph* gra,VertexType data){
	int i;
	for(i=0;i<gra->vexnum;++i){
		if(gra->xlist[i].data==data){
			return i;
		}
	}
	return -1;
}
void createDG(OLGraph* gra){
	int i,j,k;
	char v1,v2;
	pArcBox node;
	printf("create the OLGraph:\nvernum:");
	scanf("%d",&(gra->vexnum));
	printf("arcnum:");
	scanf("%d",&(gra->arcnum));
	getchar();
	for(i=0;i<gra->vexnum;++i){
		printf("xlist[%d].data:",i);
		scanf("%c",&(gra->xlist[i].data));
		getchar();
		gra->xlist[i].firstin=NULL;
		gra->xlist[i].firstout=NULL;
	}
	for(i=0;i<gra->arcnum;++i){
		printf("v1(char):");
		scanf("%c",&v1);
		getchar();
		printf("v1(char):");
		scanf("%c",&v2);
		getchar();
		j=LocateVertex(gra,v1);
		k=LocateVertex(gra,v2);
		node=(pArcBox)malloc(sizeof(ArcBox));
//		*node={i,j,gra->xlist[i].firstin,gra->xlist[i].firstout};
		node->tailvex=j;
		node->headvex=k;
		node->hlink=gra->xlist[k].firstin;
		node->tlink=gra->xlist[j].firstout;
		gra->xlist[j].firstin=node;
		gra->xlist[k].firstout=node;
	}
}
void show(OLGraph* gra){
	int i;
	pArcBox cur;
	for(i=0;i<gra->vexnum;++i){
		printf("%c-->",gra->xlist[i].data);
		cur=gra->xlist[i].firstout;
		while(cur){
			printf("%c,%c  ",gra->xlist[cur->headvex].data,gra->xlist[cur->tailvex].data);
			cur=cur->tlink;
		}
		printf("\b\n");
	}
}
int main(){
	OLGraph gra;
	createDG(&gra);
	show(&gra);
	return 0;
}
