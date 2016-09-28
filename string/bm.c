#include<stdio.h>
#include<string.h>
#define N 255
void next(char* str,int* bmBs,int len){
	int j;
	for(j=0;j<255;++j){
		bmBs[j]=len;
	}
	for(j=0;j<len-1;++j){
		bmBs[str[j]]=len-1-j;
	}
}
int patch(char* str,char* pattern,int lens,int lenp,int* bmBs){
	int i=0,j;
	while(i<=lens-lenp){
		for(j=lenp-1;str[i+j]==pattern[j]&&j>=0;--j);
			if(j<0){
				return i; 
			}else{
				i+=bmBs[str[i+j]];
			}
	}
	return -1;
}
int main(){
	char* str="ababdcbadbcsbabcdbadb";
	char* pattern="sbab";
	int index=-1;
	int bmBs[N]={0};
	next(pattern,bmBs,strlen(pattern));
	index=patch(str,pattern,strlen(str),strlen(pattern),bmBs);
	if(index>-1)
		printf("%s\n",str+index);
	else
		printf("%d\n",index);
	return 0;
}
