#include <stdio.h>
int t[200][200], ch, m, n;
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            ch = ' ';
            while (ch != '*' && ch != '?')
                scanf("%c", &ch);
            if (ch == '*')
                t[i][j] = -114514,
                t[i + 1][j + 1]++,
                t[i - 1][j + 1]++,
                t[i][j + 1]++,
                t[i + 1][j]++,
                t[i - 1][j]++,
                t[i + 1][j - 1]++,
                t[i][j - 1]++,
                t[i - 1][j - 1]++;
        }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (t[i][j] < 0)
                putchar('*');
            else
                putchar(t[i][j] + 48);
        }
        putchar('\n');
    }
    return 0;
}