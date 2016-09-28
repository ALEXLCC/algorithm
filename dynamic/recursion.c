#include<stdio.h>
#define N 100
void init(int w[],int v[],int* len,int *W){
    int i=0;
    scanf("%d",len);
    while(scanf("%d%d",w+i,v+i),++i<*len);
    scanf("%d",W);
}
int max(int a,int b){
    return a<b?b:a;
}
int solve(int i,int j,int n,int* w,int* v){
    int sum=0;
    if(i==n){
        return sum;
    }else if(j<w[i]){
        sum=solve(i+1,j,n,w,v);
    }else{
        return max(solve(i+1,j,n,w,v),solve(i+1,j-w[i],n,w,v)+v[i]);
    }
}
int main(){
    int w[N],v[N],len,W,res;
    init(w,v,&len,&W);
    res=solve(0,W,len,w,v);
    printf("res:%d\n",res);
    return 0;
}
