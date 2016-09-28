/*
 *	straight insertion sort 
 *	gcc 4.4.7-4
 *	author lijinya
 *	reference data struct C 
 * */
#include<stdio.h>
#define MAXSIZE 20
typedef int KeyType;
typedef int InfoType;
/*
 *	record type 
 * */
typedef struct{
	KeyType key;
//	InfoType data;	//other data item	
}RedType;
typedef struct{
	RedType r[MAXSIZE+1];
	int length;
}SqList;
int compare(int i,int j){
	return i<j?-1:i==j?0:1;
}
void insert_sort(SqList* sl){
	int i=2,j=0;
	for(i=2;i<=sl->length;++i){
		if(compare(sl->r[i].key,sl->r[i-1].key)<0){
			sl->r[0]=sl->r[i];
			for(j=i-1;compare(sl->r[0].key,sl->r[j].key)<0;--j){
				sl->r[j+1]=sl->r[j];
			}
			sl->r[j+1]=sl->r[0];
		}
	}
}
void show(SqList* sl){
	int i=0;
	for(i=1;i<=sl->length;++i){
		printf("[%d]:%d\n",i,sl->r[i].key);
	}
}
int main(void){
	int i=0;
	SqList sl;
	scanf("%d",&sl.length);
	for(i=1;i<=sl.length;++i){
		scanf("%d",sl.r+i);
	}
	insert_sort(&sl);
	show(&sl);
	return 0;
}
