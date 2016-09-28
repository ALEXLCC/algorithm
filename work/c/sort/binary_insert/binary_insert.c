/*
 *	date 2014/7/16
 *	author lijinya
 *	binary insert sort 
 * */
#include<stdio.h>
#define	N 20
typedef int KeyType;
typedef struct{
	KeyType key;	//key type
	//other type
}RedType;
typedef struct{
	RedType red[N+1];
	int length;
}SqList;
int compare(KeyType k1,KeyType k2){
	return k1<k2?-1:k1==k2?0:1;
}
void binary_insert(SqList* sq){
	int i=0;
	int m=0;
	int max,min;
	for(i=2;i<sq->length;++i){
		min=1;
		max=i-1;
		sq->red[0]=sq->red[i];
		while(min<=max){
			m=(min+max)/2;
			if(compare(sq->red[0].key,sq->red[m].key)<0){
				max=m-1;
			}else{
				min=m+1;
			}
		}
		for(m=i-1;m>=max+1;--m){
			sq->red[m+1]=sq->red[m];	
		}
		sq->red[max+1]=sq->red[0];
	}
}
void show(SqList* sq){
	int i=1;
	for(;i<sq->length;++i){
		printf("%d ",sq->red[i].key);
	}
	printf("\n");
}
int main(){
	int i=1;
	SqList sq;
	scanf("%d",&sq.length);
	while(scanf("%d",&sq.red[i].key),++i<=sq.length);
	binary_insert(&sq);
	show(&sq);
	return 0;
}
