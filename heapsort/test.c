#include<stdio.h>
#define N 1000
void HeapAdjust(int* arr,int s,int m){
	int i,j;
	arr[0]=arr[s];
	for(j=2*s;j<=m;j*=2){
		if(j<m&&arr[j]<arr[j+1]){
			++j;
		}
		if(arr[j]<=arr[0]){
			break;
		}
		arr[s]=arr[j];
		s=j;
	}
	arr[s]=arr[0];
}
void show(int*arr,int n){
	int i=1;
	for(;i<n+1;++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void sort(int*arr,int len){
	int i,t;
	for(i=len/2;i>0;--i){
		HeapAdjust(arr,i,len);
	}
//	show(arr,len);
	for(i=len;i>1;--i){
		t=arr[1];
		arr[1]=arr[i];
		arr[i]=t;
		HeapAdjust(arr,1,i-1);
	}	
}
void init(int* arr,int* len){
	int i=1;
	scanf("%d",len);
	while(scanf("%d",arr+i),i++<*len);
	for(;i<N+1;++i){
		arr[i]=0;
	}
}
int main(){
	int arr[N+1],len;
	init(arr,&len);
	sort(arr,len);
	show(arr,len);
	return 0;
}

