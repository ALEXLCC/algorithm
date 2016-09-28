#include<stdio.h>
#include<stdlib.h>
#define N 100000
int solve(int *s,int * t,int n){
    int mint=t[0],i,j,count=1;
    for(i=1;i<n;++i){
        if(s[i]>mint){
            ++count;
            mint=t[i];
        }
    }
    return count;
}
int main(){
    int n,*s,*t,i=0;
    scanf("%d",&n);
    s=(int *)malloc(n*sizeof(int));
    t=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;++i){
        scanf("%d%d",s+i,t+i);
    }
    n=solve(s,t,n);
    printf("%d\n",n);
    free(s);
    free(t);
    return 0;
}
