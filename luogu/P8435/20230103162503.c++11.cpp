#include<stdio.h>
#include<vector>
#include<stack>

#define maxn 500007

std::stack<int> st;
std::vector<int> anss[maxn];
std::vector<int> edge[maxn];
int dfn[maxn],low[maxn],cnt,sccnt,iscut[maxn],rootid=1,cntnode,tp;

inline int min(int a, int b){return (a < b) ? a : b;}

void tarjan(int index){
//  printf("tarjan %d\n",index);
  dfn[index] = low[index] = ++cnt;
  if(index==rootid&&edge[index].size()==0){
//  	printf("catch\n");
    anss[++cntnode].push_back(index);
  }
  st.push(index);
  for(auto u:edge[index])
    if(dfn[u]==0){
      tarjan(u);
      low[index]=min(low[index],low[u]);
      if(low[u] >= dfn[index]){ // 是割点 
  		iscut[index]=1,
  		cntnode++;
//  		printf("iscut %d\n",index);
/*
5 5
1 2
2 4
3 4
1 3
3 5

*/
 		while(tp!=u){
  		  tp = st.top();
  		  anss[cntnode].push_back(st.top());
  		  st.pop();  
		}
//  		  printf("pop %d\n",tp);
//  		printf("done\n");
  		anss[cntnode].push_back(index);
      }
    }
    else
      low[index] = min(low[index],dfn[u]);
}

int n,m,u,v,ans;
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++){
    scanf("%d%d",&u,&v);
    if(u!=v){
	  edge[u].push_back(v);
      edge[v].push_back(u);	
    } 
  }
  
  for (int i=1;i<=n;++i){
//  	printf("%d start\n",i);
	if (dfn[i]==0) 
    	rootid=i,
    	tarjan(i);
//  	printf("%d end\n",i);
  }
  
  printf("%d\n",cntnode);
  for(int i=1;i<=cntnode;i++){
  	printf("%d ",anss[i].size());
  	for(int j=0;j<anss[i].size();j++)
  		printf("%d ",anss[i][j]);
  	printf("\n");
  }
}