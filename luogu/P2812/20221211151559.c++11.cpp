#include <stdio.h>
#include <vector>
#include <stack>

#define maxn 30000

std::vector<int> edge[maxn];
std::stack<int> st;
int dfn[maxn], low[maxn], book[maxn], scc[maxn], sizee[maxn], cnt, sccnt;

inline int min(int a, int b) { return (a < b) ? a : b; }

void tarjan(int index)
{
  dfn[index] = low[index] = ++cnt;
  st.push(index);
  book[index] = 1;
  for (auto u : edge[index])
  {
    if (dfn[u] == 0)
      tarjan(u),
          low[index] = min(low[index], low[u]);
    else if (book[u])
      low[index] = min(low[index], dfn[u]);
  }
  if (dfn[index] == low[index])
  {
    sccnt++;
    while (true)
    {
      int u = st.top();
      st.pop();
      book[u] = 0;
      scc[u] = sccnt;
      sizee[sccnt]++;
      if (index == u)
        break;
    }
  }
}

int n, m, u, v, ans1,ans2, out[maxn], in[maxn];
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    while (true)
    {
      scanf("%d", &u);
      if (u == 0)
        break;
      edge[i].push_back(u);
    }
  // scanf("%d%d", &u, &v),
  //     edge[u].push_back(v);

  for (int i = 1; i <= n; i++)
    if (!scc[i])
      tarjan(i);

  for (int i = 1; i <= n; i++)
    for (auto u : edge[i])
      if (scc[i] != scc[u])
      {
        in[scc[u]]++;
        out[scc[i]]++;
      }

  for (int i = 1; i <= sccnt; i++)
  {
    if (in[i] == 0)
      ans1++;
    if (out[i] == 0)
      ans2++;
  }

  printf("%d\n%d", ans1, ans2);

  return 0;
}