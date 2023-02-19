#include <stdio.h>
#include <vector>

#define maxn 6007

int val[maxn], fa[maxn], dp[maxn][2];

std::vector<int> edge[maxn];

void dfs(int index, int root)
{
  for (auto u : edge[index])
    dfs(u, root);
  dp[index][1] += val[index];
  if (index != root)
    dp[fa[index]][1] += dp[index][0];
  dp[fa[index]][0] += std::max(dp[index][1],dp[index][0]);
}

int n, u, v;
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", val + i);
  for (int i = 1; i < n; i++)
    scanf("%d%d", &u, &v),
        fa[u] = v,
        edge[v].push_back(u);

  for (int i = 1; i <= n; i++)
    if (fa[i] == 0)
    {
      dfs(i, i);
      printf("%d", std::max(dp[i][0], dp[i][1]));
    }
  return 0;
}