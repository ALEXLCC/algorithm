#include<stdio.h>
#include<stdlib.h>
char* get_memory(int n){
	char* p=NULL;
	if(NULL==(p=(char*)malloc(n*sizeof(char)))){
		printf("malloc failed!\n");
		return NULL;
	}
	memset(p,n,0);
	strncpy(p,"welcome!",n);
	return p;
}
int main(){
	char* p=NULL;
	int size=100;
	if(NULL==(p=get_memory(size))){
		return -1;
	}
	printf("%s,0x%p\n",p,p);
	free(p);
	printf("%s,0x%p\n",p,p);
	strcpy(p,"use the free memory ");
	printf("%s,0x%p\n",p,p);
	getchar();
	return 0;
}
