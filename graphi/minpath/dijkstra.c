/*
 minimun cost spanning tree
 prim algorithm
 */
#include<stdio.h>
#define MAX_VERTEX_NUM 20
//#include<limits.h>
#define INTMAX 10000
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
			gra->arcs[i][j].adj=INTMAX;
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
//		gra->arcs[k][j].adj=gra->arcs[j][k].adj;
		getchar();
	}
}
void show(pMGraph gra){
	int i,j;
	for(i=0;i<gra->vexnum;++i){
		printf("%c\t",gra->vexs[i]);
		for(j=0;j<gra->vexnum;++j){
			printf("%d ",gra->arcs[i][j].adj<INTMAX?gra->arcs[i][j].adj:-1);
		}
		printf("\n");
	}
}
minlen find_min(pMGraph gra,int* close){
	int i,j,min=INTMAX;
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
		if(INTMAX==ml.next){
			return ;
		}
		printf("%c--%d--%c\n",ml.data,gra->arcs[locateVertex(gra,ml.data)][ml.next].adj,gra->vexs[ml.next]);
		close[ml.next]=1;
		ml=find_min(gra,close);
	}
}
void find_path(pMGraph gra,int *parent,int* path,int start){
	int i,j,min,v,k;
	int visit[MAX_VERTEX_NUM]={0};
	for(i=0;i<gra->vexnum;++i){
		path[i]=INTMAX;
		parent[i]=-1;
	//	memset(pm[i],0,sizeof(pm[i]));
	}
	for(i=0;i<gra->vexnum;++i){
		if((path[i]=gra->arcs[start][i].adj)<INTMAX){
	//		pm[start][i]=1;
			parent[i]=start;
		}
	}
//	pm[start][start]=1;
	path[start]=0;
	v=start;
	visit[v]=0;
	while(!visit[v]){
		visit[v]=1;
		min=INTMAX;
		/* find the minpath  */
		for(j=0;j<gra->vexnum;++j){
			if(!visit[j]&&path[j]<min){
				min=path[j];
				v=j;
			}
		}
//		visit[v]=1;
//		v=k;
		for(j=0;j<gra->vexnum;++j){
			if(!visit[j]&&(min+gra->arcs[v][j].adj)<path[j]){
				path[j]=min+gra->arcs[v][j].adj;
	/*			for(k=0;k<gra->vexnum;++k){
					pm[j][k]=pm[v][k];
				}
				pm[j][j]=1;
				*/
				parent[j]=v;
			}
		}
	}
}
void show_path(pMGraph gra,int* path,int *parent,int start){
	int i,j,k;
	char vex[MAX_VERTEX_NUM+1]="";
	for(i=0;i<gra->vexnum;++i){
		printf("%d ",path[i]);
	}
	printf("\n");
	for(i=0;i<gra->vexnum;++i){
		memset(vex,0,sizeof(vex));
		j=MAX_VERTEX_NUM-1;
		printf("%d  ",parent[i]);
		if(-1==parent[i]){
			vex[j]=gra->vexs[i];
			printf("j=%d,%c\n",j,gra->vexs[i]);
		}else{
			printf("j=%d,",j);
			k=i;
//			vex[j+1]=0;
			printf("ch=%c,",gra->vexs[k]);
			while(k!=-1){
				printf("[%d](%d)",k,j);
				vex[j]=gra->vexs[k];
				k=parent[k];
				--j;
			}
	//		vex[j]=gra->vexs[start];
			printf("j=%d,%s\n",j,vex+j+1);
		}
//		vex[MAX_VERTEX_NUM]=0;
//		printf("%s\n",vex+j+1);
	}
	printf("\n");
}
int main(){
	MGraph gra;
	int path[MAX_VERTEX_NUM]={0};
	int parent[MAX_VERTEX_NUM]={0};
	int start=0;
	createMG(&gra);
	show(&gra);
//	prim(&gra,3);
	find_path(&gra,parent,path,start);
	show_path(&gra,path,parent,start);
	return 0;
}
