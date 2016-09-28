/*
	j>a[i]
*	dp[i][j-0]+dp[i][j-1]+...+dp[i][j-a[k]]===
	dp[i][j]+dp[i][j-1-0]+dp[i][j-1-1]....+dp[i][j-1-a[i]]-dp[i][j-1-a[i]]
	dp[i+1][j]=dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]]
*/
#include<stdio.h>
#define MAX 1000
#define N 100
void solve(int *dp,int* count,int len,int m){
	int i,j;
	dp[0]=1;
	for(i=0;i<len;++i){
		for(j=1;j<=m;++j){
			if(count[i]<j){
				dp[j]=dp[j]+dp[j-1]-dp[j-1-count[i]];
			}else{
				dp[j]=dp[j]+dp[j-1];
			}
		}
	}
}
/*
void solve(int (*dp)[MAX],int* count,int len,int m){
	int i,j;
	for(i=0;i<len+1;++i){
		dp[i][0]=1;
	}
	for(i=0;i<len;++i){
		for(j=1;j<=m;++j){
			if(count[i]<j){
				dp[i+1][j]=dp[i][j]+dp[i+1][j-1]-dp[i][j-1-count[i]];
			}else{
				dp[i+1][j]=dp[i][j]+dp[i+1][j-1];
			}
		}
	}
*/
/*
void show(int (*dp)[MAX],int len,int m){
	int i=0,j;
	for(;i<len+1;++i){
		printf("i=%-4d",i);
		for(j=0;j<=m;++j){
			printf("%4d",dp[i][j]);
		}
		printf("\n");
	}
}
*/
void show(int *dp,int len,int m){
	int i=0,j;
		for(j=0;j<=m;++j){
			printf("%4d",dp[j]);
		}
		printf("\n");
}
void init(int* count,int* len,int* m){
	int i=0;
	scanf("%d",len);
	while(scanf("%d",count+i),++i<*len);
	scanf("%d",m);
}
int main(){
//	int dp[N][MAX]={{0}};
	int dp[MAX]={0};
	int count[N];
	int len,m;
	init(count,&len,&m);
	solve(dp,count,len,m);
	show(dp,len,m);
	return 0;
}
