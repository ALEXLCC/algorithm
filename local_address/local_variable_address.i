# 1 "local_variable_address.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "local_variable_address.c"
int* f(){
 int a=9;
 return &a;
}
main(){
 int *a=f();
 printf("%d\n",*a);
}
