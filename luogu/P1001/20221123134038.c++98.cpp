#include <stdio.h>
#include <queue>
#include <cstring>
#define int long long
using namespace std;
const int N = 26 + 7, M = 26 * 26 * 2 + 11, inf = 1 << 29;
int n, m, s, t, tot = 1, u, v, p, q, attr;
int head[N], c[M], Next[M], ver[M];
int d[N], cur[N];
void add(int x, int y, int z)
{
  // printf("add %d %d %d\n", x, y, z);
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
char c1, c2;
int a,b;
signed main()
{
  s = 1, t = 2;
  scanf("%d%d", &a,&b);
  add(1,2,a);
  add(1,2,b);

  // for (int i = 1; i <= n; ++i)
  // {
  //   do
  //   {
  //     c1 = getchar();
  //   } while (c1 < 'A' || c1 > 'Z');
  //   do
  //   {
  //     c2 = getchar();
  //   } while (c2 < 'A' || c2 > 'Z');
  //   scanf("%d", &t);
  //   add(c1 - 'A' + 1, c2 - 'A' + 1, t);
  // }

  printf("%d", dinic());
  return 0;
}