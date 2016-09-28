#include<stdio.h>
#include<string.h>
void solve(int count){
	int n=2,i,c,j,k;
	int nums[201]={1,0};
	for(i=0;n<count+1;++n){
		for(i=0,c=0;i<200;++i){
			j=c+nums[i]*n;
			nums[i]=j%10;
			c=j/10;
		}
		if(c){
			nums[i]=c;
		}
	}
	if(nums[i]){
		while(nums[i]==0)--i;
		while(i>=0){
			printf("%d",nums[i--]);
		}
		printf("\n");
	}else{
	--i;
		while(nums[i]==0)--i;
		while(i>=0){
			printf("%d",nums[i--]);
		}
		printf("\n");
	}
}
int main(){
	int n;
	while(scanf("%d",&n),n)
		if(1==n)
			printf("1\n");
		else
			solve(n);
	return 0;
}
