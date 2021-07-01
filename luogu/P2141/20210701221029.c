#include <stdio.h>
#define maxn 105
int k[maxn], book[20001],book2[20001],n, cnt;
int main()
{
	//freopen("C:\\Users\\Administrator.SC-202103191207\\Downloads\\P2141_2.in","r",stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", k + i),
            book[k[i]] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (book[k[i] + k[j]]&&!book2[k[i]+k[j]])
                cnt++,
                book2[k[i]+k[j]]=1;
        }
    printf("%d", cnt);
    return 0;
}