#include <stdio.h>
#include <queue>
#include <vector>
#include <memory.h>

const int maxn = 6e5 + 7;

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

std::vector<std::pair<int, int>> edge[maxn];
std::priority_queue<Node> q;

int n, m, s, u, v, w, tmp, k;
int dis[maxn], vis[maxn];

int end;

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  s = n * 2 + 1;
  for (int i = 1; i <= m; i++)
  {
    scanf("%d%d%d", &u, &v, &w);
    if (w)
      edge[u].push_back({v, 1}),
          edge[v].push_back({u, 1});
    else
      edge[u + n].push_back({v + n, 1}),
          edge[v + n].push_back({u + n, 1});
  }
  for (int i = 1; i <= k; i++)
    scanf("%d", &tmp),
        edge[tmp].push_back({tmp + n, 0}),
        edge[tmp + n].push_back({tmp, 0});

  edge[s].push_back({1, 0});

  edge[n].push_back({n * 2 + 2, 0});
  edge[n * 2].push_back({n * 2 + 2, 0});

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
    {
      if (dis[t.first] > dis[top.id] + t.second)
      {
        dis[t.first] = dis[top.id] + t.second;
        q.push({t.first, dis[t.first]});
      }
    }
  }

  // for (int i = 1; i <= n * 2 + 3; i++)
  //   printf("%d ", dis[i]);
  if (dis[n * 2 + 2] == 1061109567)
    printf("-1");
  else
    printf("%d ", dis[n * 2 + 2]);
}