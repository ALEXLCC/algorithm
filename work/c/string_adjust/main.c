#include<stdio.h>
#include<string.h>
#define N 1000
char source[N];
char result[N];
void solve(){
	int i=0,a=0,b=0,j=0;
	b=strlen(source)-1;
	while(a<b){
		for(i=0;i<b-a;++i){
			if(source[a+i]<source[b-i]){
				result[j++]=source[a++];
				break;
			}else if(source[a+i]>source[b-i]){
				result[j++]=source[b--];
				break;
			}
		}
	}
	if(a==b){
		result[j]=source[a];
	}
}
int main(void){
	scanf("%s",source);
	solve();
	printf("%s\n",result);
	return 0;
}

