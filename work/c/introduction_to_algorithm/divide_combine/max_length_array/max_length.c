/*
 *	file:max_length.c
 *	solve longest subarray
 *	divide and combine
 * */
#include<stdio.h>
#define N 100
#define M -10000000
#define MAX(a,b) (a)>(b)?(a):(b)
int max_cross_length(int* arr,int mid,int low,int high){
	int res,maxl,maxr,left,right,i;
	maxl=M;
	maxr=M;
	res=0;
	for(i=mid;i>=low;--i){
		res+=arr[i];
		if(res>maxl){
			maxl=res;
			left=i;
		}
	}
	res=0;
	for(i=mid+1;i<=high;++i){
		res+=arr[i];
		if(res>maxr){
			maxl=res;
			left=i;
		}
	}
	return maxl+maxr;
}
int find_maximum_subarray(int* arr,int low,int high){
	int mid,left_max,right_max,cross_max;
	if(low==high){
		return arr[low];
	}
	mid=(low+high)/2;
	left_max=find_maximum_subarray(arr,low,mid);
	right_max=find_maximum_subarray(arr,mid+1,high);
	cross_max=max_cross_length(arr,mid,low,high);
	return MAX(MAX(left_max,right_max),cross_max);
}
void solve(int* arr,int len){
	int max_length=find_maximum_subarray(arr,0,len);
	printf("%d\n",max_length);
}
void init(int* arr,int* len){
	int i=0;
	if(scanf("%d",len),*len){
		while(scanf("%d",arr+i),++i<*len);
	}else{
		printf("please input the correct length.\n");
		exit(1);
	}
}
int main(){
	int arr[N]={0};
	int len;
	init(arr,&len);
	solve(arr,len);
	return 0;
}
