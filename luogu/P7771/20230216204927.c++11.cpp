#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>

#define maxn 200007
#define maxm 400007

int outdeg[maxn],indeg[maxn];
std::stack<int> res;

int edgecnt;
std::pair<int,int> edgedat[maxm];
std::vector<int> edge[maxn];
void addedge(int u,int v){
	outdeg[u]++,indeg[v]++;
	edgedat[++edgecnt] = {u,v};
	edge[u].push_back(edgecnt);
}

bool myfun(int u,int v){
	return edgedat[u].second < edgedat[v].second;
}

int vis[maxn],fronts[maxn];
void dfs(int index){
//	for(auto u:edge[index]){
	for(int i=fronts[index];i<edge[index].size();i=fronts[index]){
		if(vis[edge[index][i]])continue;vis[edge[index][i]]=1;
		int v = edgedat[edge[index][i]].second;
		fronts[index]++;
		dfs(v);
	}
	res.push(index);
}

int n,m,u,v,startcnt,endcnt,source=1,flag;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v);	
	}
	
	for(int i=1;i<=n;i++){
		if(outdeg[i]-indeg[i] == 1)startcnt++,source=i;
		if(indeg[i]-outdeg[i] == 1)endcnt++;
		if(indeg[i] != outdeg[i]) flag=1;
	}
	
	if(flag && !(startcnt==endcnt && startcnt==1)) return puts("No")&0;
	else{
		for(int i=1;i<=n;i++)
			std::sort(edge[i].begin(),edge[i].end(),myfun);
		dfs(source);
		while(!res.empty())
			printf("%d ",res.top()),res.pop();
	}
	
	return 0;
}