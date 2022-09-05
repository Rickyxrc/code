#include <stdio.h>
#include <vector>
#include <queue>
#include <cmath>
#include <memory.h>
#define maxn 10007
struct BCJ
{
    int l[maxn];
    void init(int n)
    {
        for (int i = 1; i <= n; i++)
            l[i] = i;
    }
    int ff(int n)
    {
        return l[n] = (l[n] == n) ? n : ff(l[n]);
    }
    inline void merge(int i, int j)
    {
        l[ff(i)] = l[ff(j)];
    }
    inline bool query(int i, int j)
    {
        return ff(i) == ff(j);
    }
};
struct EDGE
{
    int u, v, w;
    bool operator<(EDGE o) const
    {
        return w < o.w;
    }
};
std::vector<std::pair<int, int>> graph[maxn];
std::priority_queue<EDGE> que;
int n,
    m, u, v, w, q;
BCJ nodes;
void solveZuida()
{
    nodes.init(n + 3);
    while (!que.empty())
    {
        // printf("%d %d %d\n", que.top().u, que.top().v, que.top().w);
        if (!nodes.query(que.top().u, que.top().v))
            graph[que.top().u]
                .push_back({que.top().v, que.top().w}),
                graph[que.top().v].push_back({que.top().u, que.top().w}),
                nodes.merge(que.top().u, que.top().v);
        que.pop();
    }
}
int depth[maxn],    //节点的深度
    fath[maxn][32], //父亲节点，类似于ST表
    minw[maxn][32],
    visit[maxn];
int s, ans = 0;
inline int min(int i, int j)
{
    return i < j ? i : j;
}
void initLCA(int index, int father, int lineWidth)
{
    fath[index][0] = father;
    depth[index] = depth[father] + 1;
    minw[index][0] = lineWidth;
    int k = log2(depth[index]) + 1;
    // printf("%d = %d\n", index, minw[index][0]);
    for (int i = 1; i <= k; i++)
        fath[index][i] = fath[fath[index][i - 1]][i - 1],
        minw[index][i] = min(minw[index][i - 1], minw[fath[index][i - 1]][i - 1]);
    // printf("%d = %d\n", index, minw[index][0]);
    for (auto t : graph[index])
    {
        if (father != t.first)
        {
            initLCA(t.first, index, t.second);
        }
    }
}
int queryLCA(int nodeA, int nodeB)
{
    //先颠倒顺序
    if (depth[nodeA] < depth[nodeB])
        return queryLCA(nodeB, nodeA);
    //将较深的节点跳到一层
    while (depth[nodeA] > depth[nodeB])
    {
        int __t = log2(depth[nodeA] - depth[nodeB]);
        ans = min(ans, minw[nodeA][__t]);
        nodeA = fath[nodeA][__t];
    }
    if (nodeA == nodeB)
        return nodeA;
    for (int jmp = log2(depth[nodeA]); jmp >= 0; jmp--)
    {
        if (fath[nodeA][jmp] != fath[nodeB][jmp])
            ans = min(ans, minw[nodeA][jmp]),
            ans = min(ans, minw[nodeB][jmp]),
            nodeA = fath[nodeA][jmp],
            nodeB = fath[nodeB][jmp];
    }
    ans = min(ans, min(minw[nodeA][0], minw[nodeB][0]));
    return fath[nodeA][0];
}
int main()
{
    memset(minw, 0x3f, sizeof(minw));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        que.push({u, v, w});
    }
    solveZuida();
    for (int i = 1; i <= n; i++)
        if (nodes.l[i] == i)
            initLCA(i, 0, 0);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &u, &v);
        if (nodes.query(u, v))
        {
            ans = 2147483647;
            queryLCA(u, v);
            printf("%d\n", ans);
        }
        else
            printf("-1\n");
    }
    return 0;
}