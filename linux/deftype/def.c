enum{
	GREEN=1,
	RED=2,
	BLUE,
	BLACK
}ColorVal;
typedef int int32;
//#define a int[10]
typedef int a[10];
main(){
//	unsigned static int32 j=10;
//	unsigned int32 j=10;
	int32 j=10;
//	int a;
//	a[10] a[10];
//	int a[10];
//	a* b;
//	a b;
//	a b[10];
//	a[10] a[10];
//	a[10] a;
//	int a[10];
//	int a;
//	a b[10];
//	a b;
	a* b[10];
	printf("%d\n",sizeof ColorVal);
	return 0;
}
