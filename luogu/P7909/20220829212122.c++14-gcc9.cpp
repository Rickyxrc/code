#include <stdio.h>
int n, L, R;
inline int max(int a, int b) { return a > b ? a : b; }
int main()
{
    scanf("%d%d%d", &n, &L, &R);
    if (L / n == R / n)
        printf("%d", R % n);
    else
        printf("%d", n - 1);
    return 0;
}