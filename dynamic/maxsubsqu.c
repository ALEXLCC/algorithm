#define N 1000
int a[N],n;
max(a,b){
	return a>b?a:b;
}
int dp[N];
solve(){
	int res=0,i,j;
	for(i=0;i<n;++i){
		dp[i]=1;
		for(j=0;j<i;++j){
			if(a[j]<a[i])
			dp[i]=max(dp[i],dp[j]+1);
		}
		res=max(res,dp[i]);
	}
	return dp[n-1];
}
main(){
	int i=0;
	scanf("%d",&n);
	while(scanf("%d",a+i),++i<n);
	printf("%d\n",solve());
	for(i=0;i<n+1;++i){
		printf("%d ",dp[i]);
	}
	printf("\n");
}
