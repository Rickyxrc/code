#include <bits/stdc++.h>
// #include <stdio.h>
// #include <vector>
// #include <algorithm>

#define maxn 100007
struct bcj
{
  int li[maxn];
  void init(int n)
  {
    for (int i = 1; i <= n; i++)
      li[i] = i;
  }
  int findf(int x) { return li[x] = (li[x] == x ? (x) : (findf(li[x]))); }
  void merge(int i, int j)
  {
    li[findf(i)] = findf(j);
  }
  bool check(int i, int j)
  {
    return findf(i) == findf(j);
  }
} bing;

std::vector<int> edge[maxn];
int n, t[2][maxn], deg[maxn], u, v;
char c1, c2, ch;
char getcha()
{
  do
    ch = getchar();
  while (!(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')));
  return ch;
}
int mapping()
{
  char ch = getcha();
  if ('A' <= ch && ch <= 'Z')
    return ch - 'A' + 1;
  if ('a' <= ch && ch <= 'z')
    return ch - 'a' + 27;
  return -1;
}
char revmapping(int i)
{
  if (i >= 1 && i <= 26)
    return i - 1 + 'A';
  if (i > 26 && i <= 52)
    return i - 27 + 'a';
  return '*';
}

void conn(int u, int v)
{
  edge[u].push_back(v);
  edge[v].push_back(u);
}

int samefa, startind, mk[maxn], jidian;

std::stack<int> res;
int vis[60][60], fronts[maxn];
void dfs(int index)
{
  for (auto u : edge[index])
  {
    if (!vis[index][u])
      vis[index][u] = vis[u][index] = 1,
      dfs(u);
  }
  res.push(index);
}

signed main()
{
  scanf("%d", &n);
  bing.init(80);
  for (int i = 1; i <= n; i++)
    u = mapping(),
    v = mapping(),
    conn(u, v),
    mk[u] = mk[v] = 1,
    deg[u]++, deg[v]++,
    bing.merge(u, v);

  for (int i = 1; i <= 52; i++)
    if (mk[i])
      if (!samefa)
        samefa = bing.findf(i);
      else if (samefa != bing.findf(i))
        return puts("No Solution") & 0;

  for (int i = 1; i <= 52; i++)
    std::sort(edge[i].begin(), edge[i].end(), std::less<int>());

  // for (int i = 1; i <= 52; i++)
  // {
  //   if (mk[i])
  //   {
  //     printf("%c tos: ", revmapping(i));
  //     for (auto u : edge[i])
  //       printf("%c ", revmapping(u));
  //     puts("");
  //   }
  // }

  for (int i = 1; i <= 52; i++)
    if (mk[i])
    {
      startind = i;
      break;
    }

  // find startind
  for (int i = 1; i <= 52; i++)
    if (deg[i] & 1)
    {
      if (jidian == 0)
        startind = i;
      jidian++;
    }
  if (jidian != 2 && jidian != 0)
    return puts("No Solution") & 0;
  if (jidian == 0)
    for (int i = 1; i <= 52; i++)
      if (deg[i])
      {
        startind = i;
        break;
      }
  //

  dfs(startind);

  while (!res.empty())
  {
    printf("%c", revmapping(res.top()));
    res.pop();
  }

  return 0;
}
/*
4
aZ
tZ
Xt
aX
*/
/*
3
aB
Bc
dE
*/
/*
8
BF
FE
DE
BD
CD
GC
AD
AG
*/