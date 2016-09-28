/*
 binary insert sort
 test by array
 date 2014/7/16
 author lijinya
 */
#include<stdio.h>
#define N 100
void sort(int* arr,int len){
	int i=0,low,high,m,tem,j;
	for(i=1;i<len;++i){
		low=0;
		high=i;
		tem=arr[i];
		while(low<=high){
			m=(low+high)/2;
			if(arr[m]<tem){
				low=m+1;
			}else{
				high=m-1;
			}
		}
		for(j=i-1;j>=high+1;--j){
			arr[j+1]=arr[j];
		}
		arr[high+1]=tem;
	}
}
void show(int* arr,int len){
	int i=0;
	for(i=0;i<len;++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void init(int* arr,int *len){
	int i=0;
	scanf("%d",len);
	while(scanf("%d",arr+i),i++<*len);
	while(i<N){
		arr[i]=0;		
		++i;
	}
}
int main(){
	int arr[N],len;
	init(arr,&len);
	sort(arr,len);
	show(arr,len);
	return 0;
}

