#include <stdio.h>
#include <queue>

#define maxn 1000007

std::deque<int> qu_max, qu_min;
int liarr[maxn], n, lenn;

void printqu(std::deque<int> qs)
{
  while (!qs.empty())
  {
    printf("<%d> ", qs.back());
    qs.pop_back();
  }
  puts("");
}

int main()
{
  scanf("%d%d", &n, &lenn);
  for (int i = 1; i <= n; i++)
    scanf("%d", liarr + i);

  for (int i = 1; i <= n; i++)
  {
    // clear back
    if (!qu_max.empty() && i - qu_max.back() >= lenn)
      qu_max.pop_back();
    // clear more
    while (!qu_max.empty() && liarr[qu_max.front()] > liarr[i])
      qu_max.pop_front();
    // push front
    qu_max.push_front(i);
    if (i >= lenn)
      printf("%d ", liarr[qu_max.back()]);
  }
  puts("");
  for (int i = 1; i <= n; i++)
  {
    // clear back
    if (!qu_min.empty() && i - qu_min.back() >= lenn)
      qu_min.pop_back();
    // clear less
    while (!qu_min.empty() && liarr[qu_min.front()] < liarr[i])
      qu_min.pop_front();
    // push front
    qu_min.push_front(i);
    if (i >= lenn)
      printf("%d ", liarr[qu_min.back()]);
  }

  return 0;
}