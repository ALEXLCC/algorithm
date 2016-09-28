#include<stdio.h>
#define N 100
void init(int w[],int v[],int* len,int* t,int dp[][N]){
    int i=0;
    scanf("%d",len);
    while(scanf("%d%d",w+i,v+i),++i<*len);
    scanf("%d",t);
    for(i=0;i<*len;++i){
        dp[0][i]=0;
        dp[i][0]=0;
    }
}
int max(int a,int b){
    return a<b?b:a;
}
int solve(int *w,int* v,int t,int n,int dp[][N]){
  /*  if(i==n){
        dp[i][j]=0;
    }else if(w[i]>j){
        dp[i+1][j]=dp[i][j];
    }else{
        dp[i+1][j]=max(dp[i][j],dp[i+1][j-w[i]]+v[i]);
    }
    */
    int i,j;
    for(i=0;i<n;++i){
        for(j=0;j<=t;++j){
            if(j<w[i]){
                dp[i+1][j]=dp[i][j];
            }else{
                dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
            }
        }
    }
    return dp[n][t];
}
int main(){
    int w[N],v[N],len,t,dp[N][N],res;
    init(w,v,&len,&t,dp);
    res=solve(w,v,t,len,dp);
    printf("\n%d\n",res);
    return 0;
}
