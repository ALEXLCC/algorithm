/*
 	char (*(*x(void))[3])(void);
 */
#include<stdio.h>
char gc='a';
char func(void){
	return gc;
}
typedef char(* pf)(void);
pf* fun(void){
	pf* p= (pf*)malloc(3*sizeof(pf));
	p[0]=func;
}
char (*(*x(void))[3])(void){
	(char(*)(void))* p=((char(*)(void))*)malloc(3*sizeof((char(*)(void))));
	p[0]=func;
	return (p[0])();
}
int main(){
	char c;
	
//	x()=fun;
//	x()[0]=func
//	c=(fun()[0])();
//	x=fun;
//	c=(x()[0])();
	c=x()[0]();
	printf("%c\n",c);
}
