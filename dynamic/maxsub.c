#define N 1000
solve(int* src,int res[],int len){
	int i,ans=1;
	res[0]=1;
	for(i=1;i<len;++i){
		if(src[i]>src[i-1]){
			ans+=1;
			res[i]=res[i-1]+1;
		}else{
			res[i]=res[i-1];
		}
	}
	return ans;
}
main(){
	int src[N]={0},res[N]={0},len,i=0;
	scanf("%d",&len);
	while(scanf("%d",src+i),++i<len);
	printf("answer:%d\n",solve(src,res,len));
	for(i=0;i<len;++i){
		printf("%d ",res[i]);
	}
	printf("\n");
}
