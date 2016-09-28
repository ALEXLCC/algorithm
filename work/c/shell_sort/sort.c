/*
 *	shell sort 
 *	date 2014/7/18
 *	author lijinya
 *
 * *
 */
 #include<stdio.h>
 #define N 1000
 void init(int *arr,int *len){
	int i=1;
 	scanf("%d",len);
	while(scanf("%d",arr+i),i++<*len);
	for(;i<N+1;++i){
		arr[i]=0;
	}
 }
void shell(int* arr,int len,int d){
	int i=0,j=0;
	for(j=d+1;j<len+1;j+=d){
		arr[0]=arr[j];
		if(arr[0]<arr[j-d]){
			for(i=j;i>0&&(arr[0]<arr[i-d]);i-=d){
				arr[i]=arr[i-d];
			}
			arr[i]=arr[0];
		}
	}
}
void sort(int* arr,int len,int* dk,int n){
	int i=0;
	for(;i<n;++i){
		shell(arr,len,dk[i]);
	}
}
void show(int* arr,int len){
	int i=1;
	for(i=1;i<len+1;++i){
		if(0==i%20){
			printf("\n");
		}
		printf("%d ",arr[i]);
	}
}
int main(){
	int arr[N+1];
	int len;
	int dk[5]={9,7,5,3,1};
	init(arr,&len);
	sort(arr,len,dk,5);
	show(arr,len);
	return 0;
}
