#include<stdio.h>
#include<vector>
#include<stack>

#define maxn 20007

std::vector<int> edge[maxn];
int dfn[maxn],low[maxn],cnt,sccnt,iscut[maxn],rootid=1,cntnode;

inline int min(int a, int b){return (a < b) ? a : b;}

void tarjan(int index){
  int c=0;
  dfn[index] = low[index] = ++cnt;
  for(auto u:edge[index])
    if(dfn[u]==0){
      tarjan(u);
      low[index]=min(low[index],low[u]);
      if(low[u] >= dfn[index] && iscut[index]==false){
      	c++;
      	if(index!=rootid||c>1)
      		iscut[index]=1,
      		cntnode++;
      }
    }
    else
      low[index] = min(low[index],dfn[u]);
}

int n,m,u,v,ans;
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
    scanf("%d%d",&u,&v),
    edge[u].push_back(v),
    edge[v].push_back(u);
  
  for (int i=1;i<=n;++i)
	if (dfn[i]==0) 
    	rootid=i,
    	tarjan(i);
  
  printf("%d\n",cntnode);
  for(int i=1;i<=n;i++)
  	if(iscut[i])
  		printf("%d ",i);
  
}