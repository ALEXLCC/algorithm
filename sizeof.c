#define NULL 0
int global=9;
static int aaa=1;
void fun(int b[100]){
	int c=sizeof(b);
}
int main(void){
	int a;
	int b[100];
	int	*p=NULL;
	a=sizeof(p);
	a=sizeof(*p);
	a=sizeof(b);
	a=sizeof(b[100]);
	
	a=sizeof(&b);
	a=sizeof(&b[0]);
	fun(b);
	return 0;
}
