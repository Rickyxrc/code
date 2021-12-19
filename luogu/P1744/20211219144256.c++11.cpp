#include<vector>
#include<queue>
#include<stdio.h>
#include<math.h>
#define maxn 105
std::vector<std::pair<int,double> >e[maxn];
std::queue<int> que;
int dxs[maxn],dys[maxn],cntin[maxn],nowin[maxn],tp1,tp2,s,t;
double ans[maxn];
int n,m;
void addedge(int a,int b){
	double t=sqrt((dxs[a]-dxs[b])*(dxs[a]-dxs[b])+(dys[a]-dys[b])*(dys[a]-dys[b]));
//	printf("push in %.2lf\n",t);
	e[a].push_back({b,t});
	e[b].push_back({a,t});
	return;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",dxs+i,dys+i),
		ans[i]=1.01e36;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&tp1,&tp2),
		addedge(tp1,tp2);
	scanf("%d%d",&s,&t);
	que.push(s),cntin[s]++,nowin[s]=1,ans[s]=0.00;
	while(!que.empty()){
		int cacheHead = que.front();
//		printf("bfs now %d \n",cacheHead);
		for( std::vector<std::pair<int,double> > ::iterator it = e[cacheHead].begin();
			it < e[cacheHead].end() ; it++ ){
				if( ans[cacheHead]+it->second < ans[it->first] ){
					if( ++cntin[it->first] == n )
						return 1%0;
					ans[it->first] = ans[cacheHead]+it->second;
					que.push(it->first);
					nowin[cacheHead] = 1;
				}
			}
		nowin[cacheHead] = 0;
		que.pop();
	}
	printf("%.2lf",ans[t]);
	return 0;
}