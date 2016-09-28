#include<stdio.h>
#define N 100
void solve(int *arr,int len,int *res){
	int i,k=0;
	res[0]=arr[0];
	for(i=1;i<len;++i){
		if(arr[i]>0){
			if(res[i-1]<=0){
				res[i]=arr[i];
				k=i;
			}else{
				int t=0,j=k;
				while(j<i){
					t+=arr[j+1];
					++j;
				}
				if(t>=0){
					res[i]+=res[k]+t;
					k=i;
				}else{
					res[i]=res[k];
				}
			}
		}else{
			if(arr[i]>res[i-1]){
				res[i]=arr[i];
			}else{
				res[i]=res[i-1];
			}
		}
	}
}
void show(int* res,int len){
	int i=0;
	for(;i<len;++i){
		printf("%d ",res[i]);
	}
	printf("\n");
}
void init(int* arr,int* len){
	int i=0;
	scanf("%d",len);
	while(scanf("%d",arr+i),++i<*len);
}
int main(){
	int arr[N]={0};
	int res[N]={0};
	int len;
	init(arr,&len);
	solve(arr,len,res);
	show(res,len);
	return 0;
}
