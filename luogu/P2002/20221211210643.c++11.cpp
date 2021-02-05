#include <stdio.h>
#include <vector>
#include <stack>

#define maxn 100007

std::vector<int> edge[maxn];
std::stack<int> st;
int dfn[maxn], low[maxn], book[maxn], scc[maxn], sizee[maxn], cnt, sccnt, need[maxn];

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

int n, m, u, v, ans, out[maxn], index;
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d", &u, &v),
        edge[u].push_back(v);

  for (int i = 1; i <= n; i++)
    if (!scc[i])
      tarjan(i);

  // printf("sccnt = %d\n", sccnt);
  // for(int i=1;i<=sccnt;i++)
  //   printf("size[%d] = %d\n",i,sizee[i]);

  for (int i = 1; i <= n; i++)
    for (auto u : edge[i])
      if (scc[i] != scc[u])
      {
        need[scc[u]] = 1;
        // printf("%d -> %d\n", scc[i], scc[u]);
        // out[scc[i]]++;
      }
  // i,u
  for (int i = 1; i <= sccnt; i++)
    // {
    // if (out[i] == 0)
    ans += !need[i];
  // }

  printf("%d", ans);

  // printf("index = %d\n",index);

  // printf("%d", sizee[index]);
  return 0;
}