#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

// #define int long long

const int N = 4000 + 5, M = 200000 * 3 + 5;
const int INF = 0x3f3f3f3f;
int n, m, tot = 1, lnk[N], cur[N], ter[M], nxt[M], cap[M], cost[M], dis[N],  s, t;
long long ret;
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
  if (u == t)
    return flow;
  vis[u] = 1;
  int ans = 0;
  for (int &i = cur[u]; i && ans < flow; i = nxt[i])
  {
    int v = ter[i];
    if (!vis[v] && cap[i] && dis[v] == dis[u] + cost[i])
    {
      int x = dfs(v, t, std::min(cap[i], flow - ans));
      if (x)
        ret += x * cost[i], cap[i] -= x, cap[i ^ 1] += x, ans += x;
    }
  }
  vis[u] = 0;
  return ans;
}

int mcmf(int s, int t)
{
  int ans = 0;
  while (spfa(s, t))
  {
    int x;
    while ((x = dfs(s, t, INF)))
      ans += x;
  }
  return ans;
}

int tmp, pp, mm, f, nn, ss;

int night(int i) { return i + n; }

signed main()
{
  scanf("%d", &n);
  s = 0, t = 2 * n + 1;
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &tmp);
    addedge(i, t, tmp, 0);        // need
    addedge(s, night(i), tmp, 0); // use
  }

  scanf("%d%d%d%d%d", &pp, &mm, &f, &nn, &ss);

  for (int i = 1; i <= n; i++)
  {
    addedge(s, i, INF, pp); // buy
    if (i + 1 <= n)
    {
      addedge(i, i + 1, INF, 0);               // keep clean
      addedge(night(i), night(i + 1), INF, 0); // keep dirty
    }
    if (i + mm <= n)
      addedge(night(i), i + mm, INF, f); // fast wash
    if (i + nn <= n)
      addedge(night(i), i + nn, INF, ss); // slow wash
  }

  int ans = mcmf(s, t);
  printf("%lld\n", ret);
  return 0;
}