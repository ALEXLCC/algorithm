/*
 *	use a  array[]  to calculate the sum
 *	as the end line of table is all the maxinumun
 *	author lijinya
 *	date 2014/7/22
 *
 * */
#include<stdio.h>
#define N 1000
int dp[N];
int max(int a,int b){
	return a>b?a:b;
}
void init(int w[],int* len,int v[],int* t){
	int i=0;
	scanf("%d",len);
	while(scanf("%d%d",w+i,v+i),++i<*len);
	scanf("%d",t);
}
int solve(int* w,int len,int* v,int t){
	int i,j;
	for(i=0;i<len;++i){
		for(j=t;j>=w[i];--j){
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	return dp[t];
}
int main(void){
	int w[N],v[N],len,t;
	init(w,&len,v,&t);
	printf("%d\n",solve(w,len,v,t));
	return 0;
}
