#include <stdio.h>
#include <map>

std::map<std::pair<int, int>, int> mp;

int n, x, y;
char opt;
int main()
{
  scanf("%d", &n);
  mp[{0,0}]=1;
  for (int i = 1; i <= n; i++)
  {
    do
      opt = getchar();
    while (opt != 'U' && opt != 'D' && opt != 'L' && opt != 'R');
    if (opt == 'U')
      y++;
    if (opt == 'D')
      y--;
    if (opt == 'L')
      x--;
    if (opt == 'R')
      x++;
    if (mp[{x, y}])
      return puts("Yes") & 0;
    // printf("%d,%d\n", x, y);
    mp[{x, y}] = 1;
  }
  return puts("No") & 0;
}