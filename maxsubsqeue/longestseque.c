#include<stdio.h>
#define N 100
void solve(int* arr,int len,int* res){
	int i,j;
	for(i=0;i<len;++i){
		for(j=0;j<=i;++j){
			if(arr[i]>arr[j]){
				res[i]=res[i]>res[j]+1?res[i]:res[j]+1;
			}
		}
	}
}
void show(int* res,int len){
	int i=0;
	for(;i<len;++i){
		printf("%d ",res[i]+1);
	}
	printf("\n");
}
void init(int* arr,int* len){
	int i=0;
	scanf("%d",len);
	while(scanf("%d",arr+i),++i<*len);
}
int main(){
	int len;
	int arr[N]={0};
	int res[N]={0};
	init(arr,&len);
	solve(arr,len,res);
	show(res,len);
	return 0;
}
