#define N 1000
int dp[N][N];
max(a,b){
    return a>b?a:b;
}
solve(int w[],int len,int v[],int t){
    int i,j,k;
    for(i=0;i<len;++i){
        for(j=0;j<=t;++j){
            for(k=0;k*w[i]<=j;++k){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j-k*w[i]]+k*v[i]);
            }
        }
    }
    return dp[len][t];
}
void init(int* w,int* v,int* len,int* t){
    int i=0;
    scanf("%d",len);
    while(scanf("%d%d",w+i,v+i),++i<*len);
    scanf("%d",t);
}
main(){
    int w[N],v[N],len,t;
    init(w,v,&len,&t);
    printf("%d\n",solve(w,len,v,t));
}
