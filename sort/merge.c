#include<stdio.h>
#define N 1000
void merge(int src[],int s,int m,int t){
	//i...m...n
	int k,j,i;
	int arr1[m+1-s],arr2[t-m];
	for(i=0;i<m+1-s;++i){
        arr1[i]=src[s+i];
	}
	for(i=0;i<t-m;++i){
        arr2[i]=src[m+1+i];
	}
	for(k=s,j=0,i=0;i<m+1-s&&j<t-m;++k){
		if(arr1[i]<arr2[j]){
			src[k]=arr1[i++];
		}else{
			src[k]=arr2[j++];
		}
	}
		while(j<t-m){
			src[k++]=arr2[j++];
		}

		while(i<m+1-s){
			src[k++]=arr1[i++];
		}
}
void sort(int* src,int s,int t){
	int m;
	if(s<t){
		m=(s+t)/2;
		sort(src,s,m);
		sort(src,m+1,t);
		merge(src,s,m,t);
	}
}
void show(int* arr,int len){
	int i=0;
	for(;i<len;++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void init(int arr[],int* len){
	int i=0;
	scanf("%d",len);
	while(scanf("%d",arr+i),++i<*len);
}
int main(){
	int src[N+1]={3,6,3,7,1,6,47,87,43};
	int len;
	sort(src,0,8);
	show(src,9);
	return 0;
}
