#include<stdio.h>
void showbits(int num){
	int a,i,bytes[32];
	a=num&1;
	bytes[31]=a;
	a=num>>1;
	for(i=30;i>=0;--i){
		bytes[i]=a&1;
		a=a>>1;
	}
	for(i=0;i<32;++i){
		printf("%d",bytes[i]);
	}
	printf("\n");
}
int main(void){
	showbits(127);
	return 0;
}
