#include<stdio.h>
#define N 120
int dp[N+1];
void solve(){
    int i,j,k;
    for(i=1;i<=N;++i){
        for(j=i;j<=N;++j){
            dp[j]+=dp[j-i];
        }
    }
}
int main(){
    int n;
    dp[0]=1;
    solve();
    while(1){
        scanf("%d",&n);
        if(n<1||n>120){
            break;
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
