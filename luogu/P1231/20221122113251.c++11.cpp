#include <iostream>
#include <queue>
#include <cstring>
#define int long long
using namespace std;
const int N = 50000 + 10, M = 80000 * 2 + 10, inf = 1 << 29;
int n, m, s, t, tot = 1, n1, n2, n3, m1, m2, u, v;
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
  scanf("%d%d%d", &n1, &n2, &n3);

  s = 0, t = 2*n1 + n2 + n3 + 1;
  for (int i = 1; i <= n1; i++)
    add(n2+i,n1+n2+i,1);
  for (int i = 1; i <= n2; i++)
    add(s, i, 1);
  for (int i = 1; i <= n3; i++)
    add(2*n1+n2+i, t, 1);
  
  scanf("%d", &m1);
  for (int i = 1; i <= m1; i++)
  {
    scanf("%d %d", &u, &v);
    add(v,n2+u,1);
  }
  scanf("%d", &m2);
  for (int i = 1; i <= m2; i++)
  {
    scanf("%d %d", &u, &v);
    add(n2+n1+u,n2+2*n1+v,1);
  }

  printf("%d",dinic());
  return 0;
}