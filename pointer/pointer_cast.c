#include<stdio.h>
int main(){
	int* pn,n;
	char c=0x65;
	pn=(char*)&c;
	printf("pn=0x%p,c=0x%p\n",pn,c);
	n=*pn;
	printf("n=%d\n",n);
	*pn=0x12345678;
	printf("pn=%d\n",*pn);
	getchar();
	return 0;
}