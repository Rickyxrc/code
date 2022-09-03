#include <stdio.h>
#include <vector>
#define maxn 500007
int n, m, s, u, v;
std::vector<int> edge[maxn];
std::vector<std::pair<int, int>> queries[maxn];
int visited[maxn], fath[maxn], rtans[maxn];
int findfth(int t)
{
    return fath[t] = (fath[t] != t ? findfth(fath[t]) : t);
}
void tarjan(int index)
{
    // printf("visit %d\n", index);
    visited[index] = 1;
    for (auto t : edge[index])
        if (!visited[t])
        {
            tarjan(t);
            // printf("setft %d = %d\n", t, index);
            fath[t] = index;
        }
    for (auto q : queries[index])
    {
        if (visited[q.first])
            rtans[q.second] = findfth(q.first);
            // printf("ansed query %d = %d\n", q.second, findfth(q.first));
    }
    // if(!visited)
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= n; i++)
        fath[i] = i;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        queries[u].push_back({v, i});
        queries[v].push_back({u, i});
    }
    tarjan(s);
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", rtans[i]);
    }
    return 0;
}