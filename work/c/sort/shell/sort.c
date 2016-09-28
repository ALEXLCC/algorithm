/*
 *	shell sort
 *	test by integer
 *	2014/7/17
 *	author lijinya
 * */
#include<stdio.h>
#define N 100
void init(int* arr,int*n){
	int i=0;
	scanf("%d",n);
	while(scanf("%d",arr+i),i++<*n);
	while(i<N){
		arr[i++]=0;
	}
}
void show(int* arr,int n){
	int i=0;
	for(;i<n;++i){
		printf("%d ",arr[i]);
		if(19==i%20){
			printf("\n");
		}
	}
}
void shell(int d,int* arr,int len){
	int i=0,t,j;
	for(i=d;i<len;++i){
		if(arr[i]<arr[i-d]){
			t=arr[i];
			for(j=i-d;j>=0&&(t<arr[j]);j-=d){
				arr[j+d]=arr[j];
			}
			arr[j+d]=t;
		}
	}
}
void sort(int* arr,int n,int* dlta,int d){
	int k;
	for(k=0;k<d;++k){
		shell(dlta[k],arr,n);
	}
}
int main(){
	int arr[N];
	int len;
	int dlta[5]={9,7,5,3,1};
	init(arr,&len);
	sort(arr,len,dlta,5);
	show(arr,len);
	return 0;
}
