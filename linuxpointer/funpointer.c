/*
 	char (*(*x(void))[3])(void);
 */
#include<stdio.h>
char gc='a';
char func(void){
	return gc;
}
typedef char(* pf)(void);
pf* x(void){
	pf* p=(pf*)malloc(3*sizeof(pf));
	p[0]=func;
}
int main(){
	char c;
//	x()[0]=func;
	c=(x()[0])();
	printf("%c\n",c);
}
