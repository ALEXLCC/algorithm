#define N 10
main(){
	int a[N+1]={1,0};
	int i,j;
	for(i=1;i<N+1;++i){
		for(j=i;j<N+1;++j){
			a[j]+=a[j-i];
		}
	}
	printf("%d\n",a[N]);
}
