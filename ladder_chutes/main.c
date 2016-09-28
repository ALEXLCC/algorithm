#include<stdio.h>
#include<stdlib.h>
#define N 10000
typedef struct _pos{
	int xPos;
	int yPos;
}pos,*p_pos;
typedef struct _queue{
	p_pos front;
	p_pos rear;
}queue,*p_queue;
p_queue create(){
	p_queue q=(p_queue)malloc(sizeof(queue));	
	q->front=q->rear=(p_pos)malloc(N*sizeof(pos));	
	return q;
}
void clear(p_queue q){
	free(q->front);
	free(q);
}
empty(p_queue q){
	if(q->front==q->rear){
		return 1;
	}
	return 0;
}
void push(p_queue q,pos p){
	*q->rear=p;
	++q->rear;
}
pos pop(p_queue q){
	++q->front;
	return *(q->front-1);
}
int main(){
	p_queue q=create();
	char board[100][100];
	int minLen[100][100];
	pos start,end;
	int n,m,i,j;
	pos dir[4]={{0,1},{-1,0},{0,-1},{1,0}};
	scanf("%d%d",&n,&m);
	scanf("%d%d",&start.xPos,&start.yPos);
	scanf("%d%d",&end.xPos,&end.yPos);
	printf("start:%d,%d\n",start.xPos,start.yPos);
	printf("end:%d,%d\n",end.xPos,end.yPos);
	getchar();
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			scanf("%c",*(board+i)+j);
		}
		getchar();
	}
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			printf("%c",board[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			minLen[i][j]=N;
		}
	}
	minLen[start.xPos][start.yPos]=0;
	push(q,start);
	printf("before while\n");
	while(!empty(q)){
		printf("After while!\n");
		pos next;
		pos cur=pop(q);
		if(cur.xPos==end.xPos&&cur.xPos==end.yPos){
			break;
		}
		for(i=0;i<4;++i){
			next.xPos=cur.xPos+dir[i].xPos;
			next.yPos=cur.yPos+dir[i].yPos;
			if(N==minLen[next.xPos][next.yPos]&&'#'!=board[next.xPos][next.yPos]&&next.xPos<m&&next.xPos>=0&&next.yPos>=0&&next.yPos>n){
				push(q,next);
				minLen[next.xPos][next.yPos]=minLen[cur.xPos][cur.yPos]+1;
				printf("pos  %d,%d  len  %d",next.xPos,next.yPos,minLen[next.xPos][next.yPos]);
			}
		}
	}
	printf("%d\n",minLen[end.xPos][end.yPos]);
	return 0;
}
