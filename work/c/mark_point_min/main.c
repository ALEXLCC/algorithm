#include<stdio.h>
#define N 1000
int len[N];
int n;
int radius;
void sort(int len[]){
	int i=0,j=0;
	for(i=0;i<n;++i){
		for(j=i+1;j<n;++j){
			if(len[i]>len[j]){
				int t=len[i];
				len[i]=len[j];
				len[j]=t;
			}
		}
	}
}
int solve(){
	int count=0,j=0,i=0;
	int start=len[0],cen;
	while(start<len[n-1]){
		cen=start+radius;
		for(i;i<n;++i){
			if(len[i]>cen){
				++count;
				break;
			}
		}
		cen=len[i-1];
		for(i;i<n;++i){
			if(len[i]>cen+radius){
				start=len[i];
				break;
			}
		}
			if(i>=n){
				break;
			}
	}
	if(start>=len[n-1]||cen>=len[i-1]){
		count++;
	}
	return count;
}
int main(){
	int i=0;
	scanf("%d%d",&n,&radius);
	while(scanf("%d",&len[i++]),i<n);
	sort(len);
	printf("%d\n",solve());
	return 0;
}
