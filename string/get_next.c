#include<stdio.h>
#include<string.h>
#define N 128
void get_next(const char* str,int* next,int len){
	int i=0,j=-1;
	next[0]=-1;
	next[-1]=0;
	for(i=0;i<len;){
		if(-1==j||str[i]==str[j]){
			++j;
			++i;
			if(str[i]!=str[j]){
				next[i]=j;
			}else{
				next[i]=next[j];
			}
//			next[i]=j;
		}else{
			j=next[j];
		}	
	}
}
void show(int* arr,int len){
	int i=0;
	for(i=0;i<len;++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int kmp(const char* src,int ls,const char* des,int ld,int s,int* next){
	int i=s,j=0;
	while(i<ls&&j<ld){
		if(-1==j||src[i]==des[j]){
			++i;
			++j;
		}else{
			j=next[j];
		}
	}
	return j-ld>=0;
}
int main(){
	char src[128],des[128];
	int arr[N]={0};
	memset(arr,-1,sizeof(arr));
	gets(src);
	gets(des);
	get_next(des,arr,strlen(des));
	show(arr,strlen(des));
	if(kmp(src,strlen(src),des,strlen(des),0,arr)){
		printf("Yes\n");
	}
	return 0;
}
