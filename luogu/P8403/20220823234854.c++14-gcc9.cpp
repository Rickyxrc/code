#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#define maxn 800007
using namespace std;
unordered_map<string, int> mp;
vector<pair<int, int>> must, musnt;
int n, fa[maxn], id;
string tx, ty, tz;
int mappinggg(string s)
{
    if (mp[s] == 0)
            mp[s] = ++id;
    return mp[s];
}
int ff(int x)
{
    return fa[x] == x ? x : fa[x] = ff(fa[x]);
}
int merge(int x, int y)
{
    x = ff(x);
    y = ff(y);
    fa[x] = fa[y];
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> tx >> ty;
        must.push_back({mappinggg(tx), mappinggg(ty)});
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> tx >> ty;
        musnt.push_back({mappinggg(tx), mappinggg(ty)});
    }
    for (int i = 1; i <= maxn - 7; i++)
        fa[i] = i;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> tx >> ty >> tz;
        merge(mappinggg(tx), mappinggg(tz));
        merge(mappinggg(ty), mappinggg(tz));
    }

    int ans = 0;
    for (auto t : must)
    {
        if (ff(t.first) != ff(t.second))
                ans++;
    }
    for (auto t : musnt)
    {
        if (ff(t.first) == ff(t.second))
                ans++;
    }
    printf("%d", ans);
    return 0;
}