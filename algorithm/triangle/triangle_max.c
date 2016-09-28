//#include<stdio.h>
int length[100];
max(a,b){
	return a<b?b:a;
}
void solve(n){
	int i,j,k,maxL=0,len=0,maxlen=0;
	for(i=0;i<n;++i){
		for(j=i+1;j<n;++j){
			for(k=j+1;k<n;++k){
				len=length[i]+length[j]+length[k];
				maxL=max(length[i],max(length[j],length[k]));
				if(maxL<len-maxL){
					maxlen=max(len,maxlen);
				}
			}
		}
	}
	printf("%d\n",maxlen);
}
main(){
	int i,n;
	scanf("%d",&n);
	while(scanf("%d",length+i),length[i++]);
	solve(n);
}
