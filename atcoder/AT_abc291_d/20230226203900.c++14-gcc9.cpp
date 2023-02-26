#include <stdio.h>
#define mod 998244353
#define maxn 200007

int n;
long long cards[2][maxn], dp[2][maxn];

signed main()
{
  scanf("%lld", &n);
  for (int i = 0; i < n; i++)
    scanf("%lld%lld", &cards[0][i], &cards[1][i]);

  dp[0][0] = dp[1][0] = 1;
  for (int i = 1; i < n; i++)
    for (int side = 0; side <= 1; side++)
      dp[side][i] = (cards[side][i] != cards[side][i - 1]) * dp[side][i - 1] +
                    (cards[side][i] != cards[side ^ 1][i - 1]) * dp[side ^ 1][i - 1],
      dp[side][i] %= mod;

  // for (int i = 0; i < n; i++)
  // {
  //   for (int side = 0; side <= 1; side++)
  //     printf("<%lld> ", dp[side][i]);
  //   puts("");
  // }

  printf("%lld", (dp[0][n - 1] + dp[1][n - 1]) % mod);
  return 0;
}