#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 5000+10, M = 2500000*2+10, inf = 1 << 29;
int n, m, s, t, tot=1;
int head[N], c[M], Next[M], ver[M];
int d[N], cur[N];
//int flg[1007][23];
void add(int x,int y,int  z) {
//	printf("connect %d %d %d\n",x,y,z);
	c[++tot]=z,ver[tot]=y,Next[tot]=head[x],head[x]=tot;
	c[++tot]=0,ver[tot]=x,Next[tot]=head[y],head[y]=tot;
}
bool bfs() {
	memset(d,-1,sizeof(d));
	queue<int> q;
	q.push(s),d[s]=0,cur[s]=head[s];
	while(q.size()) {
		int u = q.front();
		q.pop();
		for (int i  = head[u]; i; i = Next[i]) {
			int v= ver[i];
			if(d[v] == -1 && c[i]) {
				q.push(v), d[v] = d[u] + 1;
				cur[v] = head[v];
				if(v==t)return true;
			}
		}
	}
	return false;
}
int dfs(int u, int limit) {
	if(u==t) return limit;
	int flow = 0;
	for (int i=cur[u];i&&flow<limit;i=Next[i]) {
		cur[u]=i;
		int v=ver[i];
		if(c[i]!=0&&d[v]==d[u]+1) {
			int f=dfs(v,min(c[i],limit-flow));
			if(!f)d[v]=-1;
			c[i]-=f,c[i^1]+=f,flow+=f;
		}
	}
	return flow;
}
int dinic() {
	int maxflow=0,flow=0;
	while(bfs()) 
	    while(flow=dfs(s,inf))
	      maxflow+=flow;
	return maxflow;
}
int tmp,k,num;
signed main() {
	scanf("%d%d",&k,&n);
	s=0;
	t=n+k+1;
	for (int i=1;i<=k;i++) {
		scanf("%d",&tmp);
		add(n+i,t,tmp);
	}
	for (int i=1;i<=n;i++) {
		scanf("%d",&num);
		for (int j=1;j<=num;j++) {
			scanf("%d",&tmp);
			add(i,n+tmp,1);
		}
	}
	for (int i=1;i<=n;i++)
		add(s,i,1);
	//  scanf("%d%d%d%d",&n,&m,&s,&t);
	//  while(m--){
	//    int u,v,c;
	//    scanf("%d%d%d",&u,&v,&c);
	//    add(u,v,c);
	//  }
//	printf("%d",dinic());
	dinic();
	
	for(int i=1;i<=k;i++){
		printf("%d:",i);
		for (int tm  = head[n+i]; tm; tm = Next[tm]){
			if(ver[tm] != t && c[tm^1] == 0)
				printf(" %d",ver[tm]);
		}
		putchar('\n');
	}
	
	return 0;
}
/*
2 3
2 2
2 1 2
1 1
1 1
*/