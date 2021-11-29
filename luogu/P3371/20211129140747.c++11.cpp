#include<stdio.h>
#include<vector>
#include<queue>
#include<memory.h>
#include<map>
#define maxn 20008
#define DIS_INF 2147483647
std::vector<std::pair<int,int> > edge[maxn];
std::map<std::pair<int,int>,int> mp;
std::map<std::pair<int,int>,int>::iterator mpit;
int dis[maxn];
int looked[maxn];
int n,u,v,w,m,s;
int mins,minn;
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n;i++)
		dis[i] = DIS_INF;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		if(u==v){
//			printf("Jump next\n");
			continue;
		}
			
		mpit = mp.find({u,v});
		if(mpit==mp.end()){
			edge[u].push_back({v,w});
			mp[{u,v}]=edge[u].size()-1;
//			printf("Insert [%d,%d] = %d \n",u,v,edge[u].size()-1);
		}
		else{
//			printf("fetch to %d \n",std::min(edge[u][mpit->second].second,w));
			edge[u][mpit->second].second = std::min(edge[u][mpit->second].second,w);
		}
	}
	
//	for(int i=1;i<=n;i++)
//		for(std::vector<std::pair<int,int> >::iterator it = edge[i].begin();
//			it<edge[i].end(); it++ ){
//				printf("[%d,%d = %d] ",i,it->first,it->second);
//			}
	
	dis[s] = 0;
	
	for(int i=1;i<=n;i++){
//		printf("find at %d\n",i);
		mins=DIS_INF;
		minn=DIS_INF;
		for(int i=1;i<=n;i++)
			if(mins>dis[i]&&!looked[i])
				mins=dis[i],
				minn=i;
//		printf("choose %d \n",minn);
		if(minn == DIS_INF){
//			printf("ERR:unconnectalbe.\n");
//			printf("program stopped.\n");
			break;
		}
		for(std::vector<std::pair<int,int> >::iterator it = edge[minn].begin();
			it<edge[minn].end(); it++ ){
				if( dis[it->first] > dis[minn] + it->second && !looked[it->first] )
//					printf(": %d to %d to %d fetched to %d\n",s,minn,it->first,dis[minn] + it->second),
					dis[it->first] = dis[minn] + it->second;
			}
		looked[minn]=1;
	}
	
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
	
	return 0;
}