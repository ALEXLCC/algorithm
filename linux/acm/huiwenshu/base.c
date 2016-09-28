#include<stdio.h>
int isOrNot(unsigned short n,unsigned short base){
	unsigned short bits[16] ={0};
	unsigned short count,i,j;
	for(count=0;n;++count){
		bits[count]=n%base;
		n/=base;
	}
	for(i=0,j=count-1;(bits[i]==bits[j])&&i<=j;++i,--j);
	if(i>j){
		return 1;
	}
	return 0;
}
void solve(unsigned short n){
	unsigned short base=2;
	unsigned short res[15]={0};
	while(base<17){
		res[base-2]=isOrNot(n,base);
		++base;
	}
	for(base=0;base<15;++base){
		if(res[base]){
			printf("%d ",base+2);
		}
	}
}
int main(){
/*	if(isOrNot(16,2)){
		printf("Yes\n");
	}else{
		printf("not\n");
	}
	*/
	solve(65535);
}
