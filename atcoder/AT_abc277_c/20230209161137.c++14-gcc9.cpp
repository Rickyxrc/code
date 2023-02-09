#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#define maxn 400007

std::map<int, int> lsh;
int lsh_rev[maxn], vis[maxn];
int cnt = 0;

std::vector<int> edge[maxn];
std::queue<int> qu;

int n, u, uval, v, mx = 1;
inline int maxx(int a, int b)
{
  return a > b ? a : b;
}

inline int lis(int num)
{
  if (lsh[num])
    return lsh[num];
  lsh[num] = ++cnt;
  lsh_rev[cnt] = num;
  return cnt;
}

inline int grevlis(int cnt)
{
  return lsh_rev[cnt];
}

int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &u, &v),
        u = lis(u), v = lis(v),
        edge[u].push_back(v),
        edge[v].push_back(u);

  qu.push(lis(1));
  while (!qu.empty())
  {
    u = qu.front();
    uval = grevlis(u);
    qu.pop();

    if (vis[u])
      continue;
    vis[u] = 1;

    mx = maxx(mx, uval);
    for (auto s : edge[u])
      qu.push(s);
  }
  printf("%d", mx);
  return 0;
}