/**
 *	generate random numbers for shell sort test
 *	date 2014/7/28
 *	author lijinya
 *	gcc4.4.7-4
 */
#include<stdio.h>
#define N 1000
int main(){
	int i=0;
	srand(time(0));
	for(;i<N+1;++i){
		printf("%d ",rand()%1000);
	}
	printf("\n");
	return 0;
}
