#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <memory.h>

#define maxn 200007

std::vector<std::pair<int, int>> edge[maxn],edge_new[maxn];
std::stack<int> st;
int dfn[maxn], low[maxn], book[maxn], scc[maxn], sizee[maxn], cnt, sccnt, need[maxn];
int n, m, u, v, w, ans, out[maxn];

inline int min(int a, int b) { return (a < b) ? a : b; }

void tarjan(int index)
{
  dfn[index] = low[index] = ++cnt;
  st.push(index);
  book[index] = 1;
  for (auto u : edge[index])
  {
    if (dfn[u.first] == 0)
      tarjan(u.first),
          low[index] = min(low[index], low[u.first]);
    else if (book[u.first])
      low[index] = min(low[index], dfn[u.first]);
  }
  if (dfn[index] == low[index])
  {
    sccnt++;
    while (true)
    {
      int u = st.top();
      st.pop();
      book[u] = 0;
      scc[u] = sccnt;
      sizee[sccnt]++;
      if (index == u)
        break;
    }
  }
}

bool operator<(std::pair<int,int> i,std::pair<int,int> j){
  return i.second<j.second;
}
std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int> > > p;

int dis[maxn],vis[maxn];
int dijkstra(){
  memset(dis,0x3f,sizeof(dis));
  dis[scc[1]]=0;
  p.push({scc[1],0});

  while(!p.empty()){
    std::pair<int,int> u = p.top();p.pop();
    if(vis[u.first])
      continue;
    vis[u.first]=1;
    for(auto v:edge_new[u.first])
      if(dis[v.first] > dis[u.first] + v.second)
        dis[v.first] = dis[u.first] + v.second,
        p.push({v.first,dis[v.first]});
  }

  // for(int i=1;i<=sccnt;i++)
  //   printf("dis %d = %d \n",i,dis[i]);

  return dis[scc[n]];
}

int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d%d", &u, &v, &w),
        edge[u].push_back({v, w});

  for (int i = 1; i <= n; i++)
    if (!scc[i])
      tarjan(i);
  
  for (int i = 1; i <= n; i++)
    for(auto u:edge[i])
      if(scc[i] != scc[u.first]){
        // printf("%d -> %d %d\n",scc[i],scc[u.first],u.second);
        edge_new[scc[i]].push_back({scc[u.first],u.second});
      }

  printf("%d", dijkstra());
  return 0;
}