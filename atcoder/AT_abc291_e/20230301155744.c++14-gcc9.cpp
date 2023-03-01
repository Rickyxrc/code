#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
 
std::map<std::pair<int, int>, int> mp;
 
#define maxn 200007
int indeg[maxn], n, m, u, v, flg, tar;
 
std::vector<int> edge[maxn];
int dfn[maxn], cnt;
 
std::queue<int> qu;
// void dfs(int index)
// {
//   if (edge[index].size() > 0)
//     dfs(edge[index][0]);
//   dfn[index] = ++cnt;
// }
 
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
  {
    scanf("%d%d", &u, &v);
    if (mp[{u, v}])
      continue;
    mp[{u, v}] = 1;
    edge[v].push_back(u);
    indeg[u]++;
  }
 
  for (int i = 1; i <= n; i++)
    if (indeg[i] == 0)
      if (flg)
        return puts("No") & 0;
      else
        flg = 1, tar = i;
  if (tar == 0 && flg == 0)
    return puts("No") & 0;
 
  qu.push(tar);
  while (!qu.empty())
  {
    int u = qu.front();
    qu.pop();
    dfn[u] = n - (cnt++);
    flg = 0;
    for (auto t : edge[u])
    {
      indeg[t]--;
      if (indeg[t] == 0)
      {
        if (flg == 0)
          flg = 1;
        else
          return puts("No") & 0;
        qu.push(t);
      }
    }
  }
 
  for (int i = 1; i <= n; i++)
    if (dfn[i] == 0)
      return puts("No") & 0;
 
  puts("Yes");
  for (int i = 1; i <= n; i++)
    printf("%d ", dfn[i]);
  return 0;
}