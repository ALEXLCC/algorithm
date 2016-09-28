# 1 "test.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "test.c"
# 1 "sta.h" 1
static int sx=20;
void ffx(){
 printf("%d\n",sx);
}
# 2 "test.c" 2

extern int sx;
void main(){
 ffx();
}
