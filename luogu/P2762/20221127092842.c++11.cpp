#include <iostream>
#include <queue>
#include <cstring>
#define int long long
using namespace std;
const int N = 10000 + 10, M = 100000 * 2 + 10, inf = 1 << 29;
int n, m, s, t, tot, fyong,sum,anss;
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
  // ios::sync_with_stdio(false);
  // cin >>n>>m>>s>>t;
  scanf("%d%d", &m, &n);
  s = 0;
  t = m + n + 1;
  tot = 1;

  int lastt;
  char ch;

  lastt = 0;
  for (int i = 1; i <= m; i++)
  {
    // printf("LOOP\n");
    scanf("%d", &fyong);
    sum+=fyong;
    // printf("(%d)", fyong);
    add(s, i, fyong);
    lastt = 0;
    ch=getchar();
    while (true)
    {
      ch = getchar();
      // printf("[%c]", ch);
      if (isdigit(ch))
      {
        lastt = (lastt << 1) + (lastt << 3) + (ch ^ 48);
      }
      else if (ch == ' ')
      {
        // printf("|");
        // printf("<%d>", lastt);
        add(i, m + lastt, inf);
        lastt = 0;
      }
      else if (ch == '\r' || ch == '\n')
      {
        // printf("\n");
        // printf("\'%d\'\n", lastt);
        add(i, m + lastt, inf);
        lastt = 0;
        break;
      }
      else
      {
        printf("UNKNOWN CHAR [%c] %d\n", ch, ch);
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &lastt);
    add(m + i, t, lastt);
  }

  // for(int i=head[s];i;i=Next[i]){
  //   printf("[%d %d]",c[i],ver[i]);
  // }

  // for(int i=head[s];i;i=Next[i]){
  //   printf("[%d %d]",c[i],ver[i]);
  // }

  anss = sum-dinic();
  dinic();

  for(int i=1;i<=m;i++){
    if(d[i]>0)
      printf("%d ",i);
  }
  putchar('\n');
  for(int i=m+1;i<=m+n;i++){
    if(d[i]>0)
      printf("%d ",i-m);
  }
  putchar('\n');
  printf("%d",anss);
  // cout << sum-dinic() << endl;
  return 0;
}