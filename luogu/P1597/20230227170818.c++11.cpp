#include <stdio.h>
#include <cctype>
int ch, id, mpp[200];
int main()
{
  // freopen("./in.in", "r", stdin);
  while (scanf("%c:=%c;", &ch, &id) == 2)
    mpp[ch] = isdigit(id) ? id ^ 48 : mpp[id];
  printf("%d %d %d", mpp['a'], mpp['b'], mpp['c']);
  return 0;
}