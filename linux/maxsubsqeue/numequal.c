#include<stdio.h>
#define N 100
#define MAX 10000
void solve(int (*dp)[MAX+1],int* num,int* count,int len,int res){
	int i=0,j;
	memset(dp[0],-1,sizeof(dp[0]));
	for(i=1;i<=len;++i){
		dp[i][0]=count[i-1];
	}
	for(i=1;i<=len;++i){
		for(j=1;j<=res;++j){
			if(j>=num[i-1]&&dp[i][j-num[i-1]]>0){
				dp[i][j]=dp[i][j-num[i-1]]-1;
			}else if(dp[i-1][j]>=0){
				dp[i][j]=count[i-1];
			}else{
				dp[i][j]=-1;
			}
		}
	}
}
void init(int* num,int* count,int* len,int* res){
	int i=0;
	scanf("%d",len);
	while(scanf("%d%d",num+i,count+i),++i<*len);
	scanf("%d",res);
}
void show(int (*dp)[MAX+1],int len,int res){
	int i=0,j;
	for(;i<len+1;++i){
		for(j=0;j<=res;++j){
			printf("%4d",dp[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int dp[N+1][MAX+1];
	int count[N+1];
	int num[N+1];
	int len;
	int res;
	init(num,count,&len,&res);
	solve(dp,num,count,len,res);
	if(dp[len][res]>=0){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	show(dp,len,res);
	return 0;
}
