#define CONVERT(x) #x
int main(void){
	printf("%s\n",CONVERT(hello world!));
	printf("%s\n",CONVERT(100));
	printf("%s\n",CONVERT(while));
	printf("%s\n",CONVERT(return));
	return 0;
}
