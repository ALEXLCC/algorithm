extern _start;
int global=8;
int main(){
	int local=1;
	printf("_start:%p\n",&_start);
	printf("main:%p\n",main);
	return local;
}
/*
	objcopy -O object -j .text a.out test.text
	objcopy -O object -j .data a.out test.data
*/
