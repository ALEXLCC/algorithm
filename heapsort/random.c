#define N 1000
main(){
	int i=0;
	srand(time(0));
	for(i=0;i<N+1;++i){
		printf("%d ",rand()%N);
	}
	printf("\n");
}
