/*main.c*/
#include<stdio.h>
extern int StrLen(char *str);
int main(){
	char src[]="hello dymatic";
	printf("length is :%d\n",StrLen(src));
	return 0;
}
