#include <stdio.h>
#include <bitset>
long long prime[50007], size = 50000, primecnt;
char bits[10000007], book[10000007];

void getOla()
{
  for (long long i = 2; i <= size; i++)
  {
    if (bits[i] == 0)
    {
      prime[++primecnt] = i;
    }
    for (long long j = 1; j <= primecnt; j++)
    {
      if (i * prime[j] > size)
        break;
      bits[i * prime[j]] = 1;
      if (!(i % prime[j]))
        break;
    }
  }
}
signed main()
{
  // size = 50000; // 平方大于2147483647
  getOla();
  long long l, r, ans;
  scanf("%lld%lld", &l, &r);
  if (l == 1)
    l = 2;
  for (long long i = 1; i <= primecnt; ++i)
  {
    long long p = prime[i], start = ((l + p - 1) / p) * p;
    if (start < 2 * p)
      start = 2 * p;
    for (long long j = start; j <= r; j += p)
      book[j - l + 1] = 1;
  }

  for (long long i = 1; i <= r - l + 1; i++)
    ans += !book[i];
  printf("%lld", ans);
  return 0;
}