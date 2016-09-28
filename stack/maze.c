#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define N 10
#define M 10
/*
	'#' stand for barrar
	' ' stand for path
*/
typedef struct _pos{
	int x;
	int y;
//	int v;	//visited
}Pos,*pPos;
typedef struct _stack{
	pPos stack;
	pPos top;
	pPos bottom;
}Stack,*pStack;
void init(pStack sta){
	sta->bottom=sta->top=sta->stack=(pPos)malloc(MAX*sizeof(Pos));
}
void push(pStack sta,Pos cur){
	*sta->top++=cur;
}
Pos pop(pStack sta){
	return *--sta->top;
}
int empty(pStack sta){
	return sta->top==sta->bottom;
}
void solve(pStack sta,char board[][M],int dir[][2],Pos start,Pos end,int vst[][M]){
	int i,j;
	Pos cur=start,next;
	vst[cur.x][cur.y]=1;
	push(sta,start);
	while(!empty(sta)){
		for(i=0;i<4;++i){
			next.x=cur.x+dir[i][0];
			next.y=cur.y+dir[i][1];
			if((next.x==end.x)&&(next.y==end.y)){
				printf("Yes!\n");
				return;
			}
				if(next.x>=0&&next.x<=M&&next.y>=0&&next.y<=N&&!vst[next.x][next.y]&&' '==board[next.x][next.y]){
					push(sta,next);
					cur=next;
					vst[cur.x][cur.y]=1;
					break;
				}
		}
		if(i>=4){
			cur=pop(sta);
		}
	}
	printf("No!\n");
}
int main(){
	int i,j;
	int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
	char board[N][M]={
		{'#','#','#','#','#','#','#','#','#','#'},
		{'#',' ',' ','#',' ',' ',' ','#',' ','#'},
		{'#',' ',' ','#',' ',' ',' ','#',' ','#'},
		{'#',' ',' ',' ',' ','#','#',' ',' ','#'},
		{'#',' ','#','#','#',' ',' ',' ',' ','#'},
		{'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
		{'#',' ','#',' ',' ',' ','#',' ',' ','#'},
		{'#',' ','#','#','#',' ','#','#',' ','#'},
		{'#','#',' ',' ',' ',' ',' ',' ',' ','#'},
		{'#','#','#','#','#','#','#','#','#','#'},
	};
	int vst[N][M]={{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};
	pStack sta=(pStack)malloc(sizeof(Stack));
	init(sta);
	Pos start,end;
	start.x=1;
	start.y=1;
	end.x=8;
	end.y=8;
	solve(sta,board,dir,start,end,vst);
	return 0;
}
