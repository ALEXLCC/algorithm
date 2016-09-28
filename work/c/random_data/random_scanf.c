/*
 *	author lijinya
 *	2014/7/16
 *	to produce some random data
 * */
main(){
	int i=0;
	int n;
	srand(time((0)));
	scanf("%d",&n);
	for(i=0;i<n;++i){
		printf("%d ",rand()%1000);
	}
}
