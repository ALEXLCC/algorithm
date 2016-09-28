main(){
	int a=9;
	int* const p=&a;
	int b=7;
//	p=&b;
	*p=76;
}
