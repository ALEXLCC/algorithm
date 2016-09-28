# 1 "call_function.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "call_function.c"

int square(int n){
 return n*n;
}
int f(int x){
 return x;
}
int main(void){
 printf("1	%d\n",(printf("Call function %s\n","square"),square(4)));
 printf("2	%d\n",(printf("Call function %s\n","f"),f(10)));
 return 0;
}
