#include<stdio.h>
int solve(){
	int a[5]={0};
	int i=0,j=0;
	for(;;i+=5){
		a[j]=i*5+1;
		while(0==a[j]%4){
			a[j+1]=a[j]/4*5+1;
			++j;
		}
		if(j>=5){
			return a[4];
		}else{
			a[1]=0;
			a[2]=0;
			a[3]=0;
			a[4]=0;
			j=0;
		}
	}
	return 0;
}
int main(){
	int res=solve();
	printf("%d\n",res);
	return 0;
}
