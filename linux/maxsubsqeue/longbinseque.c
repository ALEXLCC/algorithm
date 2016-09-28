#include<stdio.h>
#define INF 10000000
#define N 100
void solve(int* arr,int len,int* res){
	int i,j=0;
	for(i=0;i<len;++i){
		for(j=len-1;j>=0&&(arr[i]<res[j]);--j);
		++j;
		res[j]=arr[i];
	}
}
void show(int* res,int len){
	int i=0;
	for(;i<len;++i){
		printf("%d ",res[i]);
	}
	printf("\n");
}
void init(int* arr,int* len,int* res){
	int i=0;
	scanf("%d",len);
	while(scanf("%d",arr+i),++i<*len);
	for(i=0;i<*len;++i){
		res[i]=INF;
	}
}
int main(){
	int len;
	int arr[N]={0};
	int res[N]={0};
	init(arr,&len,res);
	solve(arr,len,res);
	show(res,len);
	return 0;
}
