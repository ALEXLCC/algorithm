#include<stdio.h>
#include<math.h>
int main(void){
	double res=0.0;
	int num=0,i=0,count;
	int j,arr[32000]={0};
	scanf("%d",&count);
	while(i<count){
		scanf("%d",&num);
		for(j=1;j<num+1;++j){
			res+=log10(j);
		}
		arr[i]=(int)res+1;
		res=0.0;
		++i;
	}
	for(i=0;i<count;++i){
		printf("%d\n",arr[i]);
	}
	return 0;
}
