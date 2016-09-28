/*
 *	author lijinya
 *	2014/7/16
 *	to produce some random data
 * */
main(){
	int i=0;
	srand(time((0)));
	for(i=0;i<1000;++i){
		if(39==i%40){
			printf("\n");
		}
		printf("%d ",rand()%1000);
	}
}
