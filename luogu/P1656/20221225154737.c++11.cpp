#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>

#define maxn 10000
#define maxm 10007

inline int min(int a, int b){return (a < b) ? a : b;}

int gecnt; 
std::pair<int,int> arr[maxm];

struct Graph{
	int head[maxn],next[maxm],to[maxn],cnt=1;
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
//		printf("running cut %d %d\n",index,faedgeid);
		dfn[index] = low[index] = ++cntdfn;
//		printf("low , dfn = %d,%d\n",low[index],dfn[index]);
		for(int i=head[index];i!=0;i=next[i]){
			int y = to[i];
//			printf("%d -> %d\n",index,y);
//			printf("%d %d %d\n",i,faedgeid^1,i==faedgeid^1);
			if(dfn[y]==0){
//				printf("CUTEDGE DOWN\n");
				runcutedge(y,i);
//				printf("run done,now %d\n",index);
//				if(low[y]<low[index])
				
//				if(low[y] < low[index])
//					printf("low[%d] upd to %d\n",index,low[index]);
//				else
//					printf("low[%d] don\'t update \n",index);
				low[index] = min(low[index],low[y]);
				if(low[y] > dfn[index])
					if(index<y)
						arr[++gecnt] = {index,y};
					else
						arr[++gecnt] = {y,index};
//					printf("%d %d\n",index,y);
			}
			else if(i != (faedgeid^1) )
//				printf("not rev edge %d -> %d\n",index,y),
				low[index] = min(low[index],low[y]);
//				printf("!! low [%d] upd to %d\n",index,low[index]);
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
//  for(int i=1;i<=n;i++)
//    tarjan(i);
//  
//  for(int i=1;i<=sccnt;i++)
//    ans+=sizee[i]>1;
  
//  printf("%d",ans);
}
/*
6 6
1 2
2 3
3 4
4 5
4 6
*/