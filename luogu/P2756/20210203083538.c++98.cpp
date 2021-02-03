#include<bits/stdc++.h>
using namespace std;
const int N = 100 + 10, M = 100 * 100 + 400, inf = 1 << 29;
int n, m, s, t, tot;
int head[N], c[M], Next[M], ver[M];
int d[N], cur[N];
void add(int x,int y,int z) {
    c[++tot]=z,ver[tot]=y,Next[tot]=head[x],head[x]=tot;
    c[++tot]=0,ver[tot]=x,Next[tot]=head[y],head[y]=tot;
}
bool bfs() {
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(s), d[s] = 0, cur[s] = head[s];
    while (q.size()){
        int u = q.front();
        q.pop();
        for (int i  = head[u]; i; i = Next[i]) {
            int v = ver[i];
            if (d[v] == -1 && c[i]) {
                q.push(v), d[v] = d[u] + 1;
                cur[v] = head[v];
                if (v == t)
                    return true;
            }
        }
    }
    return false;
}
int dfs(int u, int limit){
    if (u == t)
        return limit;
    int flow = 0;
    for (int i = cur[u];i&&flow < limit; i = Next[i]) {
        cur[u] = i;
        int v = ver[i];
        if (c[i] != 0 && d[v] == d[u] + 1) {
            int f = dfs(v, min(c[i], limit - flow));
            if (!f)
                d[v] = -1;
            c[i] -= f, c[i ^ 1] += f, flow += f;
        }
    }
    return flow;
}
int dinic() {
    int maxflow=0,flow=0;
    while (bfs())
        while (flow = dfs(s,inf))
        	maxflow += flow;
    return maxflow;
}
int main() {
    ios::sync_with_stdio(false); 
	cin>>m>>n;
    s = 0, t = n + 1;
    tot = 1;
    for (int i = 1; i <= m; i++)
        add(s,i,1);
    for (int i = m + 1; i <= n; i++)
        add(i,t,1);
    int u=0,v=0 ;
    while(cin>>u>>v,u!=-1)
        add(u,v,1);
    cout<<dinic();
    for(int i=2;i<=tot;i+=2)
    	if(ver[i]>m&&ver[i]<=n&&!c[i])
			cout<<endl<<ver[i^1]<<" "<<ver[i];
    //        <<" "<<(i^1)<<" "<<i; 
    //cout<<endl;
    //for(int i=1;i<=tot;i++)
    //   cout<<" "<<ver[i];
    return 0;
}