/*
 *	quick sort 
 *	low high pivotery
 *	low++ high--	
 *	test by integer
 *	author lijinya
 *	date 2014/7/17
 * */
#include<stdio.h>
#define N 1000
int partition(int* arr,int low,int high){
	arr[0]=arr[low];
	while(low<high){
		while(low<high&&(arr[0]<=arr[high])){
			--high;
		}
		arr[low]=arr[high];
		while(low<high&&(arr[0]>=arr[low])){
			++low;
		}
		arr[high]=arr[low];
	}
	arr[low]=arr[0];
	return low;
}
void init(int* arr,int* len){
	int i=1;
	scanf("%d",len);
	while(scanf("%d",arr+i),i++<*len);
	for(i;i<N+1;++i){
		arr[i]=0;
	}
}
void show(int* arr,int len){
	int i=1;
	for(;i<len+1;++i){
		if(0==i%20){
			printf("\n");
		}
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void insert(int* arr,int len){
	int t,i,j,k;
	for(i=1;i<len;++i){
		t=arr[i];
		for(j=i-1;(j>=0)&&(arr[j]>t);--j){
			
		}
		for(k=i-1;k>j;--k){
			arr[k+1]=arr[k];
		}
		arr[j+1]=t;
	}
}
void quick(int* arr,int low,int high){
	int index;
	if(low<high){
		index=partition(arr,low,high);
		quick(arr,low,index-1);
		quick(arr,index+1,high);
	}
}
int main(void){
	int arr[N+1];
	int len;
	init(arr,&len);
	quick(arr,1,len);
	show(arr,len);
	return 0;
}
