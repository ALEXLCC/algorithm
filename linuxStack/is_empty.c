/*
 	empty.c
	is_empty(void);
 */
extern char stack[512];
extern int top;
int is_empty(void){
	return top==-1;
}
