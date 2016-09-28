#include<stdio.h>
using namespace std;
#include<queue>
#define NN 10000
#define PL 1000000
int L,P,N;
int A[NN+1],B[NN+1];
void solve(){
	A[N]=0;
	B[N]=0;
	N++;
	priority_queue<int> que;
	int ans=0,pos=0,tank=P;
	for(int i=0;i<N;++i){
		int d=L-A[i]-pos;
		while(tank-d<0){
			if(que.empty()){
				puts("-1");
				return;
			}
			tank+=que.top();
			que.pop();
			++ans;
		}
		tank-=d;
		pos=L-A[i];
		que.push(B[i]);
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d%d",A+i,B+i);
	}
	scanf("%d%d",&L,&P);
	solve();
	return 0;
}
