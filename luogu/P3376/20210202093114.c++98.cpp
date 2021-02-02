#include<bits/stdc++.h>
using namespace std;
const int N=1000+10,M=10000*2+10;
int n,m,s,t,tot;
long long maxflow;
int head[N];
long long c[M];
int ver[M],Next[M];
void add(int x,int y,int z){
	c[++tot]=z,ver[tot]=y,Next[tot]=head[x],head[x]=tot;
	c[++tot]=0,ver[tot]=x,Next[tot]=head[x],head[x]=tot;
}
int vis[N],pre[N];
long long incf[N];
const int inf=1<<29;
bool bfs(){
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(s),vis[s]=1;
	incf[s]=inf;
	while(q.size()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=Next[i]){
			if(c[i]){
				int v=ver[i];
				if(vis[v])continue;
				incf[v]=min(incf[u],c[i]);
				pre[v]=i;
				q.push(v),vis[v]=1;
				if(v==t)
					return 1;
			}
		}
	}
	return 0;
}
void update(){
	int u=t;
	while(u!=s){
		int i=pre[u];
		c[i]-=incf[t];
		c[i^1]+=incf[t];
		u=ver[i^1];
	}
	maxflow+=incf[t];
}
int main(){
	cin>>n>>m>>s>>t;
	tot=1;
	maxflow=0;
	while(m--){
		int u,v,c;
		cin>>u>>v>>c;
		add(u,v,c);
	}
	while(bfs())update();
	cout<<maxflow;
	return 0;
}