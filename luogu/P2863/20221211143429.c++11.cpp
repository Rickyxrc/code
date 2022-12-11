#include<stdio.h>
#include<vector>
#include<stack>

#define maxn 10007

std::vector<int> edge[maxn];
std::stack<int> st;
int dfn[maxn],low[maxn],book[maxn],scc[maxn],sizee[maxn],cnt,sccnt;

inline int min(int a, int b){return (a < b) ? a : b;}

void tarjan(int index){
  dfn[index] = low[index] = ++cnt;
  st.push(index);book[index]=1;
  for(auto u:edge[index]){
    if(dfn[u]==0)
      tarjan(u),
      low[index]=min(low[index],low[u]);
    else if(book[u])
      low[index] = min(low[index],dfn[u]);
  }
  if(dfn[index] == low[index]){
    sccnt++;
    while(true){
      int u=st.top();st.pop();
      book[u]=0;
      scc[u] = sccnt;
      sizee[sccnt]++;
      if(index==u)break;
    }
  }
}

int n,m,u,v,ans;
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
    scanf("%d%d",&u,&v),
    edge[u].push_back(v);
  
  for(int i=1;i<=n;i++)
    tarjan(i);
  
  for(int i=1;i<=sccnt;i++)
    ans+=sizee[i]>1;
  
  printf("%d",ans);
}