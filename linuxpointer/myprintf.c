/*
 	myprintf
	printf(const char*format,... );
 */
#include<stdio.h>
#include<stdarg.h>
void myprintf(const char* format,...){
	va_list ap;
	char c,ch,*p;
	va_start(ap,format);
	while(c=*format++){
		switch(c){
			case 'c':
				ch=va_arg(ap,int);
				putchar(ch);
				break;
			case 's':
				p=va_arg(ap,char*);
				fputs(p,stdout);
//				fputs(p,1);
				break;
			default:
				putchar(c);
		}
	}
	va_end(ap);
}
int main(){
	char c='1';
	myprintf("c\ts\n",c,"hello");
	return 0;
}
