#include<vector>
#include<queue>
#include<stdio.h>
#include<math.h>
#include<stdio.h>
#include<memory.h>
#define maxn 310
std::vector<std::pair<int,int> >e[maxn];
std::queue<int> que;
int cntin[maxn],nowin[maxn],d,p,c,f,tp1,tp2,tp3,ans[maxn],anss;
int n,m;
int main(){
	memset(ans,0x3f,sizeof(ans));
	scanf("%d%d%d%d",&d,&p,&c,&f);
	for(int i=1;i<=p;i++)
		scanf("%d%d",&tp1,&tp2),
		e[tp1].push_back({tp2,-d});
	
	for(int i=1;i<=f;i++)
		scanf("%d%d%d",&tp1,&tp2,&tp3),
		e[tp1].push_back({tp2,tp3-d});
		
	for(int i=1;i<=c;i++)
		e[0].push_back({i,-d});
	
	que.push(0),cntin[0]++,nowin[0]=1,ans[0]=0;
	while(!que.empty()){
		int cacheHead = que.front();
		for( std::vector<std::pair<int,int> > ::iterator it = e[cacheHead].begin();
			it < e[cacheHead].end() ; it++ ){
				if( ans[cacheHead]+it->second < ans[it->first] ){
					if( ++cntin[it->first] > c ){
						puts("orz");
						return 0;
					}
					ans[it->first] = ans[cacheHead]+it->second;
					que.push(it->first);
					nowin[cacheHead] = 1;
				}
			}
		que.pop();
		nowin[cacheHead] = 0;
	}
	for(int i=1;i<=c;i++)
		anss = std::min(anss,ans[i]);
	printf("%d",-anss);
	return 0;
}
