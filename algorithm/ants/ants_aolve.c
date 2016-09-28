#include<stdio.h>
int min(int a,int b){
	return a<b?a:b;
}
max(a,b){
	return a<b?b:a;
}
void solve(int n,int arr[],int L){
	int i=0;
	int minT=0;
	int maxT=0;
	for(i=0;i<n;++i){
		minT=max(minT,min(arr[i],L-arr[i]));
	}
	for(i=0;i<n;++i){
		maxT=max(maxT,max(arr[i],L-arr[i]));
	}
	printf("min=%d,max=%d\n",minT,maxT);
}
int main(void){
	int n,i,L,arr[100000];
	scanf("%d",&L);
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",arr+i);
	}
	solve(n,arr,L);
	return 0;
}
