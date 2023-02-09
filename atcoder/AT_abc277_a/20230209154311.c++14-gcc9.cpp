#include <stdio.h>

int n, x, t;
int main()
{
  scanf("%d%d", &n, &x);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &t);
    if (x == t)
      return printf("%d", i) & 0;
  }
  return 0;
}