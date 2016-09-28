#include<iostream>
using namespace std;
#define N 50000
#define K 100000
class Union{
private:
	int par[N];
	int rank[N];
public:
	Union(){}
	void init(int n);
	bool same(int x,int y);
	int find(int x);
	void unite(int x,int y);
};
void Union::init(int n){
		for(int i=0;i<n;++i){
			par[i]=i;
			rank[i]=0;
		}
	}
int Union::find(int x){
		if(par[x]==x){
			return x;
		}else{
			return par[x]=find(par[x]);
		}
	}
void Union::unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y){
		return;
	}
	if(rank[x]<rank[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(rank[x]==rank[y]){
			rank[x]++;
		}
	}
}
bool Union::same(int x,int y){
	return find(x)==find(y);
}
int main(){
	Union un;
	int n,ans=0,words;
	cin>>n>>words;
	if(n>N||words>K){
		return -1;
	}
	un.init(n*3);
	for(int i=0;i<words;++i){
		int w;
		int x;
		int y;
		cin>>w>>x>>y;
		if(x>n||y>n||x<0||y<0){
			++ans;
			continue;
		}
		if(w==1){
			if(un.same(x,y+n)||un.same(x,y+2*n)){
				++ans;
			}else{
				un.unite(x,y);
				un.unite(x+n,y+n);
				un.unite(x+2*n,y+2*n);
			}
		}else if(w==2){
			if(un.same(x,y)||un.same(x,y+2*n)){
				++ans;
			}else{
				un.unite(x,y+n);
				un.unite(x+n,y+2*n);
				un.unite(x+2*n,y);
			}
		}
	}
	cout<<ans<<endl;
	cin.get();
	cin.get();
	return 0;
}
