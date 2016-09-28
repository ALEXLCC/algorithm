#include<stdio.h>
#define N 100
int main(){

	int i,j,k,t;
	int a,count,c;
	while(scanf("%d%d",&a,&count),a){
		int source[N]={0};
		int result[N+2]={0};
		c=0;
		j=0;
		for(i=0;i<count;++i){
			source[i]=a;
			c=0;
			for(k=0;k<=i;++k){	
				t=result[k]+source[k]+c;
				result[k]=t%10;
				c=t/10;	
			}
			if(c>0){
				result[k]=c;
			}
		}
		if(result[i]){
			printf("%d",result[i]);
		}
		for(j=i-1;j>=0;--j){
			printf("%d",result[j]);
		}
		printf("\n");
	}
	return 0;
}