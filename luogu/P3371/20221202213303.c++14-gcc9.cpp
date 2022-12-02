#include<stdio.h>
#include<vector>
#include<memory>
#include<queue>

#define maxn 10007

std::vector<std::pair<int, int> > edge[maxn];
std::queue<int> q;

int n,m,s,u,v,w;
int val[maxn];

int main(){
  scanf("%d%d%d",&n,&m,&s);
  for(int i=1;i<=m;i++){
    scanf("%d%d%d",&u,&v,&w);
    edge[u].push_back(std::make_pair(v,w));
  }

  for(int i=1;i<=n;i++){
    val[i] = 2147483647;
  }
  val[s] = 0;
  q.push(s);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(auto t:edge[u]){
      if(val[t.first] > val[u] + t.second){
        val[t.first] = val[u] + t.second;
        q.push(t.first);
      }
    }
  }

  // for(int i=1;i<=n;i++){
  //   
  //     if(val[t.first] > val[i] + t.second)
  //       val[t.first] = val[i] + t.second;
  //     // printf("[%d %d %d]\n",i,t.first,t.second);
  //   }
  // }

  for(int i=1;i<=n;i++){
    printf("%d ",val[i]);
  }

  return 0;
}