/*
 main.c
 pop
 push
 empty
 stack.h
 */
#include"stack.h"
#include<stdio.h>
int main(){
	push('a');
	push('s');
	printf("%c\n",pop());
	return 0;
}
