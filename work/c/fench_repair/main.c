/*
 *	gcc 4.7
 *	date 2014/7/14
 *	fence repair 
 *	poj 3253
 * */
#include<stdio.h>
#include<stdlib.h>
int n;
void swap(int* p,int i,int j){
	int t=p[i];
	p[i]=p[j];
	p[j]=t;
}
int solve(int *p){
	int res=0;
	int min1=0,min2=1,i=2,t;
	while(n>1){
		min1=0,min2=1;
		if(p[min1]>p[min2]){
			swap(p,min1,min2);
		}
		for(i=2;i<n;++i){
			if(p[i]<p[min1]){
				min2=min1;
				min1=i;
			}else if(p[i]<p[min2]){
				min2=i;
			}
		}
		t=p[min1]+p[min2];
		res+=t;
		if(min1==n-1){
	//		swap(p,min1,min2);
		}
		p[min1]=t;
		p[min2]=p[n-1];
		--n;
	}
	return res;
}
int main(void){
	int *len,i=0;
	scanf("%d",&n);
	len=(int*)malloc(n*sizeof(int));
	while(scanf("%d",len+i++),i<n);
	printf("%d\n",solve(len));
	free(len);
	return 0;
}
