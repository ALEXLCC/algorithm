#include<stdio.h>
#define ENDSTRING '\0'
int StrLen(char* string){
	int len=0;
	while(ENDSTRING!=*string++)
		++len;
	return len;
}
