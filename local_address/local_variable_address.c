int* f(){
	int a=9;
	return &a;
}
main(){
	int *a=f();
	printf("%d\n",*a);
}
