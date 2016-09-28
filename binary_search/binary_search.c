#include<stdio.h>
int search(int* arr,int n,int f){
	int m,a,b;
	a=0;b=n;
	while(a<=b){
		m=(a+b)/2;
		if(arr[m]<f){
			a=m+1;
		}else if(arr[m]>f){
			b=m-1;
		}else{
			return 1;
		}
	}
	return 0;
}
main(){
	int arr[7]={1,2,3,4,5,6,7};
	if(search(arr,7,4)){
		printf("find...\n");
	}else{
		printf("not find...\n");
	}
}
