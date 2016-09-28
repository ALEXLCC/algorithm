#include<stdio.h>
#define CONST_NAME1 "CONST_NAME1"
#define CONST_NAME2 "CONST_NAME2"
#line 15 "file.c"
void f(){
	return 0;
}
int main(void){
	printf("%s\n",CONST_NAME1);
	printf("%s\n",CONST_NAME2);
	printf("%d\n",__LINE__);
	printf("%s\n",__FILE__);
	f();
	return 0;
}
