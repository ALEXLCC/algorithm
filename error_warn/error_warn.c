//#include<stdio.h>
//#define COMMAND "_COMMAND"
#define CONST_NAME1 "CONST_NAME1"
#define CONST_NAME2 "CONST_NAME2"
int main(void){
	#ifndef COMMAND
	#warning Compilation will be stoped ...
	#error No defined Constant Symbol COMMAND
	#endif

	printf("%s\n",COMMAND);
	printf("%s\n",CONST_NAME1);
	printf("%s\n",CONST_NAME2);
	return 0;
}
