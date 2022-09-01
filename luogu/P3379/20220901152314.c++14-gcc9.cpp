#include <stdio.h>
#include <vector>
#include <cmath>
#define maxn 500007
std::vector<int> edge[maxn]; //链式前向星
int depth[maxn],             //节点的深度
    fath[maxn][32];          //父亲节点，类似于ST表
int n, m, s;
int u, v;
void initLCA(int index, int father)
{
    // printf("INITLCA %d %d\n", index, father);
    fath[index][0] = father;
    depth[index] = depth[father] + 1;
    int k = log2(depth[index]) + 1;
    for (int i = 1; i <= k; i++)
        fath[index][i] = fath[fath[index][i - 1]][i - 1];
    // for (int t = 0;t<edge[index].size();t++){
    //     if (father != edge[index][t])
    //         initLCA(edge[index][t], index);
    // }
    for (auto t : edge[index])
    {
        // printf("<%d> ", t);
        if (father != t)
            initLCA(t, index);
    }
}
int queryLCA(int nodeA, int nodeB)
{
    // printf("QUERYLCA %d,%d\n", nodeA, nodeB);
    //先颠倒顺序
    if (depth[nodeA] < depth[nodeB])
        return queryLCA(nodeB, nodeA);
    //将较深的节点跳到一层
    while (depth[nodeA] > depth[nodeB])
    {
        int __t = log2(depth[nodeA] - depth[nodeB]);
        // printf("nodeA at %d\n", nodeA);
        nodeA = fath[nodeA][__t];
    }
    if (nodeA == nodeB)
        return nodeA;
    for (int jmp = log2(depth[nodeA]); jmp >= 0; jmp--)
    {
        if (fath[nodeA][jmp] != fath[nodeB][jmp])
            nodeA = fath[nodeA][jmp],
            nodeB = fath[nodeB][jmp];
    }
    return fath[nodeA][0];
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i < n; i++)
        scanf("%d%d", &u, &v),
            edge[u].push_back(v),
            edge[v].push_back(u);
    initLCA(s, 0);
    // for (int i = 0; i <= 10; i++)
    // {
    //     for (int j = 0; j <= 10; j++)
    //         printf("%d ", fath[i][j]);
    //     printf("\n");
    // }
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &u, &v),
            printf("%d\n", queryLCA(u, v));
    return 0;
}