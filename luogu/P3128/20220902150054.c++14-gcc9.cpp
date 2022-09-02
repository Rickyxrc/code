#include <stdio.h>
#include <vector>
#include <cmath>
#define maxn 500007
std::vector<int> edge[maxn]; //链式前向星
int depth[maxn],             //节点的深度
    fath[maxn][32],          //父亲节点，类似于ST表
    diff[maxn];              //边权化点再差分
int n, m, s,ans=0;
int u, v;
void initLCA(int index, int father)
{
    fath[index][0] = father;
    depth[index] = depth[father] + 1;
    int k = log2(depth[index]) + 1;
    for (int i = 1; i <= k; i++)
        fath[index][i] = fath[fath[index][i - 1]][i - 1];
    for (auto t : edge[index])
    {
        if (father != t)
            initLCA(t, index);
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
void treePointSequnenseAdd(int S,int T){
    diff[S]++;
    diff[T]++;
    int LCA = queryLCA(S,T);
    diff[LCA]--;
    diff[fath[LCA][0]]--;
}
void solve(int index,int father){
    //更新点权（从下到上）
    for(auto t:edge[index])//遍历index下的边
        if(t!=father)//不能向父亲递归，避免成环
            solve(t, index), //向下搜索
                diff[index] += diff[t];
}
int main()
{
    scanf("%d%d", &n,&m);
    for (int i = 1; i < n; i++)
        scanf("%d%d", &u, &v),
            //读入主要边
            edge[u].push_back(v),
            edge[v].push_back(u);
    initLCA(1, 0);
    for (int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);
        treePointSequnenseAdd(u, v);//树上点差分
    }
    solve(1, 0);//进行前缀和处理
    for (int i = 1; i <= n;i++){
        // printf("%d", diff[i]);
        ans = ans > diff[i] ? ans : diff[i];
        // //从2开始是因为边1-0没有意义
        // if(diff[i]==1)
        //     //1条附加边，刚好看完，方案+1
        //     ans += 1;
        // if(diff[i]==0)
        //     //0条附加边，任意砍一条，方案+m
        //     ans += m;
        //其他无解
    }
    printf("%d", ans);
    // initLCA(1, 0);
    // scanf("%d", &m);
    // for (int i = 0; i <= 10; i++)
    // {
    //     for (int j = 0; j <= 10; j++)
    //         printf("%d ", fath[i][j]);
    //     printf("\n");
    // }
    // for (int i = 1; i <= m; i++)
    //     scanf("%d%d", &u, &v),
    //         printf("%d\n", depth[u] + depth[v] - 2 * depth[queryLCA(u, v)]);
    return 0;
}