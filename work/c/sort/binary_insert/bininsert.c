/*
 *	date 2014/7/16
 *	author lijinya
 *	binary insert sort 
 * */
#include<stdio.h>
#define	N 100
typedef int KeyType;
int compare(KeyType k1,KeyType k2){
	return k1<k2?-1:k1==k2?0:1;
}
void binary_insert(KeyType* sq,int len){
	int i=0,j=0;
	int m=0;
	int high,low;
	for(i=2;i<len+1;++i){
		low=1;
		high=i-1;
		sq[0]=sq[i];
		while(low<=high){
			m=(low+high)/2;
			if(compare(sq[0],sq[m])<0){
				high=m-1;
			}else{
				low=m+1;
			}
		}
		for(j=i-1;j>=high+1;--j){
			sq[j+1]=sq[j];	
		}
		sq[high+1]=sq[0];
	}
}
void show(KeyType* sq,int len){
	int i=1;
	for(;i<len+1;++i){
		printf("%d ",sq[i]);
	}
	printf("\n");
}
void init(KeyType* sq,int* len){
	int i=1;
	scanf("%d",len);
	while(scanf("%d",sq+i),i++<*len);
	while(i<N+1){
		sq[i++]=0;
	}
}
int main(){
	int len;
	KeyType sq[N+1];
	init(sq,&len);
	binary_insert(sq,len);
	show(sq,len);
	return 0;
}
