#define N 1000
int dp[N][N];
max(a,b){
    return a>b?a:b;
}
void init(int* w,int* len,int * v,int* t){
    int i=0;
    scanf("%d",len);
    while(scanf("%d%d",w+i,v+i),++i<*len);
    scanf("%d",t);
}
solve(int* w,int len,int* v,int t){
    int i,j;
    for(i=0;i<len;++i){
        for(j=0;j<=t;++j){
            if(j<w[i]){
                dp[i+1][j]=dp[i][j];
            }else{
                dp[i+1][j]=max(dp[i][j],dp[i+1][j-w[i]]+v[i]);
            }
        }
    }
    return dp[len][t];
}
main(){
    int w[N],v[N],len,t;
    init(w,&len,v,&t);
    printf("%d\n",solve(w,len,v,t));
}
