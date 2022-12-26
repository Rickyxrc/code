#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>

#define maxn 157
#define maxm 10007

inline int min(int a, int b){return (a < b) ? a : b;}

int gecnt; 
std::pair<int,int> arr[maxm];

struct Graph{
	int head[maxn],next[maxm],to[maxm],cnt=1;
	void ad(int u,int v) {
		to[++cnt] = v;
		next[cnt] = head[u];
		head[u] = cnt;
	}
	
	void add2wayedge(int u,int v) {
		ad(u,v);
		ad(v,u);
	}
	
	int dfn[maxn],low[maxn],cntdfn;
	void runcutedge(int index=1,int faedgeid=0) {
		dfn[index] = low[index] = ++cntdfn;
		for(int i=head[index];i!=0;i=next[i]){
			int y = to[i];
			if(dfn[y]==0){
				runcutedge(y,i);
				low[index] = min(low[index],low[y]);
				if(low[y] > dfn[index])
					if(index<y)
						arr[++gecnt] = {index,y};
					else
						arr[++gecnt] = {y,index};
			}
			else if(i != (faedgeid^1) )
				low[index] = min(low[index],low[y]);
		}
	}
}gr;

int n,m,u,v,ans;
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
    scanf("%d%d",&u,&v),
    gr.add2wayedge(u,v);
  
  gr.runcutedge();
  
  sort(arr+1,arr+gecnt+1);
  
  for(int i=1;i<=gecnt;i++)
  	printf("%d %d\n",arr[i].first,arr[i].second);
}