#include<stdio.h>
#define N 100
void sort(int* arr,int len){
    int max=arr[0],i,j,exp=1;
    for(i=1;i<len;++i){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    while(max/exp){
        int b[len];
        for(i=0;i<len;++i){
            b[i]=arr[i]/exp%exp;
        }

        exp*=10;
    }
}
