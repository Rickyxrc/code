#include <stdio.h>
#include <queue>

#define maxn 100007
#define int long long
int vals[maxn], dp[maxn], dval[maxn], n, k;

std::deque<int> qu_max;

int squ(int index)
{
  dval[index] = dp[index - 1] - vals[index];
  while (!qu_max.empty() && dval[qu_max.front()] < dval[index])
    qu_max.pop_front();
  qu_max.push_front(index);
  while (!qu_max.empty() && qu_max.back() < index - k)
    qu_max.pop_back();
  // printf("squ %lld = (%lld)%lld\n", index, qu_max.back(), dval[qu_max.back()]);
  return dval[qu_max.back()];
}

signed main()
{
  qu_max.push_back(0);
  scanf("%lld%lld", &n, &k);
  for (int i = 1; i <= n; i++)
    scanf("%lld", &vals[i]);
  for (int i = 1; i <= n; i++)
    vals[i] += vals[i - 1];
  for (int i = 1; i <= n; i++)
    dp[i] = squ(i) + vals[i];

  printf("%lld", dp[n]);

  return 0;
}