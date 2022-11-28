#include<iostream>
#include<queue>
#include<cstring>
//#define int long long
using namespace std;
const int N = 20007+10, M = 240007*2+10, inf = 1 << 29;
int n, m, s, t, tot=1;
int head[N], c[M], Next[M], ver[M],tp;
int d[N], cur[N];
void add(int x,int y,int  z){
//	printf("add %d %d %d\n",x,y,z);
  	c[++tot]=z,ver[tot]=y,Next[tot]=head[x],head[x]=tot;
  	c[++tot]=0,ver[tot]=x,Next[tot]=head[y],head[y]=tot;
}
bool bfs(){
  memset(d,-1,sizeof(d));
  queue<int> q;
  q.push(s),d[s]=0,cur[s]=head[s];
  while(q.size()) {
    int u = q.front(); q.pop();
    for(int i  = head[u]; i; i = Next[i]) {
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
  for(int i=cur[u];i&&flow<limit;i=Next[i]){
    cur[u]=i;
    int v=ver[i];
    if(c[i]!=0&&d[v]==d[u]+1){
      int f=dfs(v,min(c[i],limit-flow));
      if(!f)d[v]=-1;
      c[i]-=f,c[i^1]+=f,flow+=f;
    }
  }
  return flow;
}

int dinic(){
  int maxflow=0,flow=0;
  while(bfs()) 
    while(flow=dfs(s,inf))
      maxflow+=flow;
  return maxflow;
}

int calcxy(int i,int j){return i+(j-1)*m;}

signed main(){
	scanf("%d%d",&m,&n);
	s=n*m+2;t=n*m+1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&tp);
			if(tp == 2)
				add(s,calcxy(i,j),inf);
			if(tp == 1)
				add(calcxy(i,j),t,inf);
		}
	}
	
	for(int i=1;i<m;i++)
		for(int j=1;j<=n;j++)
			add(calcxy(i,j),calcxy(i+1,j),1);

	for(int i=1;i<=m;i++)
		for(int j=1;j<n;j++)
			add(calcxy(i,j),calcxy(i,j+1),1);
	
	for(int i=2;i<=m;i++)
		for(int j=1;j<=n;j++)
			add(calcxy(i,j),calcxy(i-1,j),1);
			
	for(int i=1;i<=m;i++)
		for(int j=2;j<=n;j++)
			add(calcxy(i,j),calcxy(i,j-1),1);

	printf("%d",dinic());
	return 0;
}
/*

2 3
1 0 2
0 0 2

*/