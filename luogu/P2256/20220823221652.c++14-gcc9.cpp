#include <iostream>
#include <map>
#define maxn 20007
using namespace std;
map<string, int> mp;
string s, s2;
int fa[maxn];
void init()
{
    for (int i = 1; i < maxn; i++)
        fa[i] = i;
}
int ff(int x)
{
    return fa[x] = fa[x] == x ? x : ff(fa[x]);
}
int merge(int x, int y)
{
    x = ff(x);
    y = ff(y);
    fa[x] = y;
}
int main()
{
    init();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        mp[s] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> s >> s2;
        merge(mp[s], mp[s2]);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> s >> s2;
        if (ff(mp[s]) == ff(mp[s2]))
            cout << "Yes." << endl;
        else
            cout << "No." << endl;
    }
    return 0;
}