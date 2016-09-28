#include<stdio.h>
#define N 100
void init(int* arr,int *len,int* adr){
	int i=1;
	scanf("%d",len);
	while(scanf("%d",arr+i),i++<*len);
	for(i=1;i<*len+1;++i){
		adr[i]=i;
	}
}
void show(int* arr,int len){
	int i=0;
	for(;i<len+1;++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int part(int* arr,int s,int t,int* adr){
	int i=s,j=t;
	arr[0]=arr[adr[s]];
	while(i<j){
		while(arr[adr[j]]>arr[0]){
			--j;
		}
		adr[i]=adr[j];
		while(arr[adr[i]]<arr[0]){
			++i;
		}
		adr[j]=adr[i];
	}
	adr[i]=adr[s];
	return i;
}
void qsort(int* arr,int s,int t,int* adr){
	if(s<t){
		int k=part(arr,s,t,adr);
		qsort(arr,s,k,adr);
		qsort(arr,k+1,t,adr);
	}
}
void sort(int* arr,int len,int* adr){
	int i,j,k;
	qsort(arr,1,len,adr);
	show(adr,len);
	for(i=1;i<len;++i){
		if(adr[i]!=i){
			j=i;
			arr[0]=arr[i];
			while(adr[j]!=i){
				k=adr[j];
				arr[j]=arr[k];
				adr[j]=j;
				j=k;
			}
			adr[j]=arr[0];
			adr[j]=j;
		}
		show(arr,len);
	}
}
int main(){
	int arr[N]={0};
	int adr[N]={0};
	int len;
	init(arr,&len,adr);
	sort(arr,len,adr);
	show(arr,len);
	return 0;
}
