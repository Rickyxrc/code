#include<stdio.h>
#include<vector>
#include<queue>
#define maxn 114514
#define __INF 0x3f3f3f3f
int n,m,tu,tv,tw;
std::vector<int>v[maxn];
std::queue<int> q;
int indu[maxn],cities[maxn];
int maxxx(int x,int y){return x>y?x:y;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&tu,&tv);
		v[tu].push_back(tv);
		indu[tv]++;
	}
	for(int i=1;i<=n;i++){
		cities[i]=-__INF;
		if(indu[i]==0)
			cities[i]=1,
			q.push(i);
	}
	while(!q.empty()){
		int tn = q.front();
		q.pop();
		for(auto i:v[tn]){
			cities[i] = maxxx(cities[i],cities[tn]+1);
			if(--indu[i]==0)
				q.push(i);
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",cities[i]);
	return 0;
}