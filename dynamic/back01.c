max(a,b){
	return a>b?a:b;
}
solve(int* res,int *w,int *v,int len,int t){
	int i,j;
	for(i=0;i<len;++i){
		for(j=t;j>=w[i];--j){
			res[j]=max(res[j],res[j-w[i]]+v[i]);
		}
	}
	return res[t];
}
main(){
	int w[4]={2,1,3,2};
	int v[4]={3,2,4,2};
	int t=5;
	int res[6]={0};
	printf("%d\n",solve(res,w,v,4,5));
}
