int foo();
int bar();
int main(){
	foo(2);
//	foo(2,3,4);
	return 0;
}
int bar(int c,int d){
	int e=c+d;
	return e;
}
int foo(int a,int b){
	return bar(a,b);
}
