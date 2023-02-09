#include <stdio.h>
#include <algorithm>

typedef unsigned long long ull;

#define maxn 400007
ull arr[maxn], arrsum[maxn], cnt, n, m, t, summ, maxx;

ull gmx(ull x, ull y)
{
  return x > y ? x : y;
}

signed main()
{
  scanf("%llu%llu", &n, &m);

  if (n == 1)
  {
    return puts("0") & 0;
  }

  for (ull i = 1; i <= n; i++)
    scanf("%llu", &t),
        arr[i] = t,
        summ += t;

  std::sort(arr + 1, arr + n + 1);

  for (ull i = 1; i <= n; i++)
  {
    if (arr[i] - arr[i - 1] > 1)
      cnt++;
    arrsum[cnt] += arr[i];
  }

  if (arr[n] == m - 1 && arr[1] == 0 && cnt > 0)
    // printf("merge"),
    arrsum[0] += arrsum[cnt], cnt--;

  for (ull i = 0; i <= cnt; i++)
    // printf("<%llu>", arrsum[i]),
    maxx = gmx(arrsum[i], maxx);

  printf("%llu", summ - maxx);
  return 0;
}
/*
4 7
1 4 5 6

5 7
0 1 4 5 6
*/