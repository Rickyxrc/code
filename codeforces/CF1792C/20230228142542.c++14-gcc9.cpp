#include <stdio.h>
#define maxn 200007
int T, tmp, n, li[maxn], yxmin;
int main()
{
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      scanf("%d", &tmp), li[tmp] = i;
    yxmin = n >> 1;
    while (yxmin > 0 && li[yxmin] < li[yxmin + 1] && li[n - yxmin + 1] > li[n - yxmin])
      yxmin--;
    printf("%d\n", yxmin);
  }
  return 0;
}