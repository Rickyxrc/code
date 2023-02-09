#include <stdio.h>
#include <map>
int vals[20007];

bool valid1(char c)
{
  return c == 'H' || c == 'D' || c == 'C' || c == 'S';
}
bool valid2(char c)
{
  return c == 'A' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == 'T' || c == 'J' || c == 'Q' || c == 'K';
}
bool valid3(char c1, char c2)
{
  // printf("<%d>", c1 * 129 + c2);
  if (vals[c1 * 129 + c2])
    return false;
  else
  {
    vals[c1 * 129 + c2] = 1;
    return true;
  }
}
bool validd(char c1, char c2)
{
  // printf("validd\n");
  return valid1(c1) && valid2(c2) && valid3(c1, c2);
}

int n, vfl;
char c1, c2;
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    do
    {
      c1 = getchar();
    } while (c1 == ' ' || c1 == '\n' || c1 == '\r');
    do
    {
      c2 = getchar();
    } while (c2 == ' ' || c2 == '\n' || c2 == '\r');

    // printf("[%c][%c]\n", c1, c2);
    if (vfl == 0 && validd(c1, c2) == false)
      vfl = 1;
    // puts(valid(c1, c2) ? "Yes" : "No");
  }
  puts(vfl ? "No" : "Yes");
  return 0;
}