#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

const int N = 50500 + 5, M = 25112345 * 2 + 5;
const int INF = 0x3f3f3f3f;
int n, m, tot = 1, lnk[N], cur[N], ter[M], nxt[M], cap[M], cost[M], dis[N], ret, stat[55][55];
bool vis[N];

void add(int u, int v, int w, int c)
{
  ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot, cap[tot] = w, cost[tot] = c;
}

void addedge(int u, int v, int w, int c)
{
  // printf("add %d %d %d %d\n", u, v, w, c);
  add(u, v, w, c), add(v, u, 0, -c);
}

bool spfa(int s, int t)
{
  memset(dis, 0x3f, sizeof(dis));
  memcpy(cur, lnk, sizeof(lnk));
  std::queue<int> q;
  q.push(s), dis[s] = 0, vis[s] = 1;
  while (!q.empty())
  {
    int u = q.front();
    q.pop(), vis[u] = 0;
    for (int i = lnk[u]; i; i = nxt[i])
    {
      int v = ter[i];
      if (cap[i] && dis[v] > dis[u] + cost[i])
      {
        dis[v] = dis[u] + cost[i];
        if (!vis[v])
          q.push(v), vis[v] = 1;
      }
    }
  }
  return dis[t] != INF;
}

int dfs(int u, int t, int flow)
{
  if(flow==0)
    return 0;
  if (u == t)
    return flow;
  vis[u] = 1;
  int maxflow = 0;
  for (int &i = cur[u]; i && maxflow < flow; i = nxt[i])
  {
    int v = ter[i];
    if (!vis[v] && cap[i] && dis[v] == dis[u] + cost[i])
    {
      int x = dfs(v, t, std::min(cap[i], flow - maxflow));
      if (x)
        ret += x * cost[i], cap[i] -= x, cap[i ^ 1] += x, maxflow += x;
    }
  }
  vis[u] = 0;
  return maxflow;
}

int dinic(int s, int t)
{
  int maxflow = 0;
  while (spfa(s, t))
  {
    int x;
    while ((x = dfs(s, t, INF)))
      maxflow += x;
  }
  return maxflow;
}

int x, y, val, s, t, k;

int main()
{
  scanf("%d%d", &n, &k);

  s = 0, t = 2*n*n + 1;

  addedge(s, 1, k,0);
  addedge(2*n*n, t, k,0);
  for(int i=1;i<=n*n;i++){
    scanf("%d",&val);
    addedge(i,i+n*n,1,-val);
    addedge(i,i+n*n,k-1,0);
  }

  for(int i=1;i<=n*n;i++){
    if((i - 1) / n + 1 != n)
      addedge(i+n*n,i+n,k,0);
    if((i - 1) % n + 1!=n)
      addedge(i+n*n,i+1,k,0);
    // printf("[%d %d %d]\n",i,(i - 1) / n + 1,(i - 1) % n + 1);
  }
  // addedge(2 * n * n + 1, t, INF,0);
  // addedge(t,2 * n * n + 1, 0, 0);

  // for (int i = 1; i <= n; i++)
  //   addedge(0, i, INF,0);
  // for (int i = 1; i < n; i++)
  //   addedge(0, 1 + i * n, INF,0);
  // for (int i = 1; i <= n; i++)
  //   addedge(n * (n - 1) + i + n * n, 2*n*n + 1, INF,0);
  // for (int i = 1; i <= n; i++)
  //   addedge(i * n + n * n, 2*n*n + 1, INF,0);
  // for (int i = 1; i <= n * n; i++)
  // {
  //   if ((i - 1) % n + 1 == n)
  //   {
  //     continue;
  //   }
  //   addedge(i + n * n, i + 1, INF,0);
  // }
  // for (int i = 1; i <= n * (n - 1); i++)
  //   addedge(i + n * n, i + n, INF,0);

  // for (int i = 1; i <= n; i++)
  //   for (int j = 1; j <= n; j++)
  //   {
  //     scanf("%d", &val);
  //     stat[i][j] = val;
  //   }

  // for (int i = 1; i <= n * n; i++)
  // {
  //   addedge(i, i + n * n, k-1, 0);
  //   addedge(i, i + n * n, 1, -stat[(i - 1) / n + 1][(i - 1) % n + 1]);
  // }

  int maxflow = dinic(s, t);
  printf("%d\n", -ret);
  return 0;
}