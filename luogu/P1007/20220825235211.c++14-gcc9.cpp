#include <cstdio>
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
int n, l, t, minn, maxx;
int main()
{
    scanf("%d%d", &l, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t);
        minn = max(minn,min(t, l + 1 - t));
        maxx = max(maxx,max(t, l + 1 - t));
    }
    printf("%d %d", minn, maxx);
}