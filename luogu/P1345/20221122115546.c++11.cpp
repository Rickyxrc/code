#include <iostream>
#include <queue>
#include <cstring>
#define int long long
using namespace std;
const int N = 207 + 10, M = 700 * 2 * 2 + 11, inf = 1 << 29;
int n, m, s, t, tot = 1, c1, c2, u, v;
int head[N], c[M], Next[M], ver[M];
int d[N], cur[N];
void add(int x, int y, int z)
{
  // printf("add %d %d %d\n",x,y,z);
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
signed main()
{
  ios::sync_with_stdio(false);
  scanf("%d%d%d%d", &n, &m, &c1, &c2);
  for(int i=1;i<=n;i++){
    add(i,i+n,1);
  }
  for(int i=1;i<=m;i++){
    scanf("%d%d",&u,&v);
    add(u+n,v,114514);
    add(v+n,u,114514);
    // add(v,u+n,114514);
  }
  c1 = c1+n;
  s=c1,t=c2;
  // printf("%d - %d\n",c1,c2);
  printf("%d", dinic());
  return 0;
}