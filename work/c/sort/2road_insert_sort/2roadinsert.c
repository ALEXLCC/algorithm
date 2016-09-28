/**
 *	author lijinya
 *	2014/7/17
 *	2 road insert sort 
 *	use a assistant room to insert
 *	the assistant mmemory use as a circle array
 * */
#include<stdio.h>
#define N 100
typedef int KetType;
typedef struct{
	KeyType arr[N+1];
	KeyType *first;
	KeyType *final;
	int length;
}SqList;
void init(SqList* sq){
	int i=1;
	scanf("%d",&sq->length);
	while(scanf("%d",sq->arr+i),i++<sq->length+1);
	while(i<N+1){
		sq->arr[i]=0;
	}
}
void show(SqList* sq){
	int i=1;
	for(;i<sq->length+1;++i){
		printf("%d ",sq->arr[i]);
	}
}
void sort(SqList* sq){
	SqList s;
	KeyType* cur,p;
	int i=1;
	s.arr[1]=sq->arr[1];
	s.length=sq->length;
	s.final=s.first=s->arr+1;
	for(i=2;i<sq->length;++i){
		cur=s.final;
		s.arr[0]=sq->arr[i];
		while(cur>=s.first){
			if(*cur>s.arr[0]){
				--cur;
			}
			if(s.arr==cur){
				cur=s.arr+s.length;
			}
		}	
		for(p=s.final;p>=cur+1;--p){
			*(p+1)=*p;
		}
		*(cur+1)=s.arr[0];
	}
	for(i=1;i<s.length;++i){
		sq->arr[i]=
	}
}
int main(void){
	SqList sq;
	init(&sq);
	sort(&sq);
	show(&sq);
	return 0;
}
