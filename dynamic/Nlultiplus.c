#include<stdio.h>
#define N 120
int dp[N+1][N+1];
void init(){
    int i,j;
    for(i=0;i<N+1;++i){
        for(j=0;j<N+1;++j){
            dp[i][j]=1;
        }
    }
}
int solve(int n){
    int i,j,k;
    for(i=2;i<=n;++i){
        for(j=2;j<=i;++j){
   /*   */  dp[i][j]=dp[i][j-1];
            for(k=1;k*j<=i;++k){
                if(i-k*j>j-1){
                    dp[i][j]+=dp[i-k*j][j-1];
                }else{
                    dp[i][j]+=dp[i-k*j][i-k*j];
                }
            }
      //      dp[i][j]+=dp[i][j-i];
        }
    }
    return dp[n][n];
}
int main(){
    int n;
    init();
    while(1){
        scanf("%d",&n);
        if(n<1||n>120){
            break;
        }
        printf("%d\n",solve(n));
    }
    return 0;
}
