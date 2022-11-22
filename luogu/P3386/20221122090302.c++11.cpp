#include <bits/stdc++.h>
using namespace std;
const int N = 1007, M = 500*500+114, inf = 1 << 29;
int n, m, s, t, tot,e;
int head[N], c[M], Next[M], ver[M];
int d[N], cur[N],mapp[N>>1][N>>1];
void add(int x, int y, int z)
{
  c[++tot] = z, ver[tot] = y, Next[tot] = head[x], head[x] = tot;
  c[++tot] = 0, ver[tot] = x, Next[tot] = head[y], head[y] = tot;
}
bool bfs()
{
  memset(d, -1, sizeof(d));
  queue<int> q;
  q.push(s), d[s] = 0, cur[s] = head[s];
  while (q.size())
  {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = Next[i])
    {
      int v = ver[i];
      if (d[v] == -1 && c[i])
      {
        q.push(v), d[v] = d[u] + 1;
        cur[v] = head[v];
        if (v == t)
          return true;
      }
    }
  }
  return false;
}
int dfs(int u, int limit)
{
  if (u == t)
    return limit;
  int flow = 0;
  for (int i = cur[u]; i && flow < limit; i = Next[i])
  {
    cur[u] = i;
    int v = ver[i];
    if (c[i] != 0 && d[v] == d[u] + 1)
    {
      int f = dfs(v, min(c[i], limit - flow));
      if (!f)
        d[v] = -1;
      c[i] -= f, c[i ^ 1] += f, flow += f;
    }
  }
  return flow;
}
int dinic()
{
  int maxflow = 0, flow = 0;
  while (bfs())
    while (flow = dfs(s, inf))
      maxflow += flow;
  return maxflow;
}
int main()
{
  ios::sync_with_stdio(false);
  cin >>  n >> m >> e;
  s=0, t = n+m+1;
  tot = 1;

  for (int i = 1; i <= n; i++)
    // printf("%d -> %d\n",s,i),
    add(s, i, 1);
  for (int i = n+1; i <= m+n; i++)
    // printf("%d -> %d\n",i,t),
    add(i, t, 1);
  
  int u = 0, v = 0;
  for(int i=1;i<=e;i++){
    cin>>u>>v;
    if(!mapp[u][v]){
      // printf("%d -> %d\n",u,v+n);
      mapp[u][v]=1;
      add(u,v+n,1);
    }
  }

  cout << dinic();
  return 0;
}