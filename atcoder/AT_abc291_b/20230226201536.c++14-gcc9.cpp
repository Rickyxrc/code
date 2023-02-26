#include <stdio.h>
#include <algorithm>
#define maxn 10000

int k;
int li[maxn];
long long sum;
int main()
{
  scanf("%d", &k);
  for (int i = 0; i < k * 5; i++)
    scanf("%d", li + i);

  std::sort(li, li + k * 5);

  // for (int i = 0; i < k * 5; i++)
  // printf("[%d]", li[i]);
  // puts("");

  for (int i = k; i < k * 4; i++)
    // printf("<%d>", li[i]),
    sum += li[i];

  //
  printf("%.8lf", (sum * 1.0) / (k * 3.0));
  //   std::sort(li,li+5);
  // for(int t=1;t<=3;t++){
  // }
  // putchar('\n');
  // }
}