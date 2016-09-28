/*
 *	01 backpage problem
 *	number n, weight  Wi,  value  Vi
 *	total weight less than W, find the max total value.
 *	author lijinya
 *	2014/7/15
 * */
#include<stdio.h>
#define N 100
int n;
int w[N];
int v[N];
int tw;
int dp[N][N];
int max(int a,int b){
	return a<b?b:a;
}
int solve(int i,int j){
	if(dp[i][j]>=0){
		return dp[i][j];
	}
	int res=0;
	if(i==n){
		res=0;
	}else if(j<w[i]){
		res=solve(i+1,j);
	}else{
		res=max(solve(i+1,j),solve(i+1,j-w[i])+v[i]);
	}
	return dp[i][j]=res;
}
void init(){
	int i=0;
	scanf("%d",&n);
	scanf("%d",&tw);
	while(scanf("%d%d",w+i,v+i),++i<n);
	memset(dp,-1,sizeof(dp));
}
int main(){
	init();
	printf("%d\n",solve(0,tw));
	return 0;
}
