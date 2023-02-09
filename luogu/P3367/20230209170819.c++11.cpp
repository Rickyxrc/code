#include <stdio.h>

#define maxn 200007

struct bcj
{
  int t[maxn];
  void init(int n)
  {
    for (int i = 1; i <= n; i++)
      t[i] = i;
  }
  int findf(int x)
  {
    return t[x] = (t[x] == x ? t[x] : findf(t[x]));
  }
  void merge(int i, int j)
  {
    t[findf(i)] = t[findf(j)];
  }
  bool query(int i, int j)
  {
    return t[findf(i)] == t[findf(j)];
  }
};

bcj a;
int n, m, type, u, v;
int main()
{
  scanf("%d%d", &n, &m);
  a.init(n);
  for (int i = 1; i <= m; i++)
  {
    scanf("%d%d%d", &type, &u, &v);
    if (type == 1)
    {
      a.merge(u, v);
    }
    else
    {
      putchar(a.query(u, v) ? 'Y' : 'N');
      putchar('\n');
    }
  }
  return 0;
}