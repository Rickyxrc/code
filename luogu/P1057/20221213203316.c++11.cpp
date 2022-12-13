#include <stdio.h>

int dp[37][37], n, m;

int roundd(int rid)
{
  if (rid == 0)
    return n;
  if (rid == n + 1)
    return 1;
  return rid;
}

int main()
{
  scanf("%d%d", &n, &m);
  dp[0][0] = 1;
  for (int round = 1; round <= m; round++)
  {
    for (int pos = 0; pos < n; pos++)
      dp[round][pos] = dp[round - 1][(pos - 1 + n) % n] + dp[round - 1][(pos + 1) % n];
    // printf("%d ", dp[round][pos]);
    // putchar('\n');
  }

  printf("%d", dp[m][0]);
  return 0;
}