#include <stdio.h>
#include <queue>
#include <vector>
#include <memory.h>

const int maxn = 100000 + 7;

struct Node
{
  int id, val;
};

bool operator<(Node a, Node b)
{
  return a.val > b.val;
}

inline int min(int a, int b)
{
  return a < b ? a : b;
}

std::vector<std::pair<int, int>> edge[maxn], edger[maxn];
std::priority_queue<Node> q;

int n, m, s, u, v, w;
int dis[maxn], disr[maxn], vis[maxn];

int main()
{
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 1; i <= m; i++)
    scanf("%d%d%d", &u, &v, &w),
        edge[u].push_back({v, w}),
        edger[v].push_back({u, w});

  memset(dis, 0x3f, sizeof(dis));
  dis[s] = 0;
  q.push({s, 0});
  while (!q.empty())
  {
    Node top = q.top();
    q.pop();
    if (vis[top.id])
      continue;
    vis[top.id] = 1;
    for (auto t : edge[top.id])
      if (dis[t.first] > dis[top.id] + t.second)
        dis[t.first] = dis[top.id] + t.second,
        q.push({t.first, dis[t.first]});
  }

  memset(disr, 0x3f, sizeof(disr));
  memset(vis, 0, sizeof(vis));
  disr[s] = 0;
  q.push({s, 0});
  while (!q.empty())
  {
    Node t = q.top();
    q.pop();
    if (vis[t.id])
      continue;
    vis[t.id] = 1;
    for (auto u : edger[t.id])
      if (disr[u.first] > disr[t.id] + u.second)
        disr[u.first] = disr[t.id] + u.second,
        q.push({u.first, disr[u.first]});
  }

  int mxx = -1;
  for (int i = 1; i <= n; i++)
    mxx = mxx > disr[i] + dis[i] ? mxx : disr[i] + dis[i];
  printf("%d", mxx);
}