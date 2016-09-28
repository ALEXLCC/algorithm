#include<stdio.h>
void solve(){
	int i=1,j=0;
	int res[6]={0};
	for(;;i+=5){
		res[0]=i;
		while(1==res[j]%5){
			res[j+1]=(res[j]-1)/5*4;
			++j;
			if(j>=5){
				printf("%d\n",res[0]);
				return;
			}
		}
		while(j){
			res[j]=0;
			--j;
		}
	}
}
int main(){
	solve();
	return 0;
}
