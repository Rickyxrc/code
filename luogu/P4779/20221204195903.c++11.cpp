#include<stdio.h>
#include<queue>
#include<vector>
#include<memory.h>

const int maxn = 100000 + 7;

struct Node {
	int id, val;
};

bool operator<(Node a,Node b){
	return a.val>b.val;
}

inline int min(int a,int b){
	return a<b?a:b;
}

std::vector<std::pair<int,int> > edge[maxn];
std::priority_queue<Node> q;

int n,m,s,u,v,w;
int dis[maxn],vis[maxn];

int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back({v,w});
	}
	
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	
	q.push({s,0});
	
	while(!q.empty()){
		Node top = q.top();q.pop();
		if(vis[top.id])
			continue;
		vis[top.id]=1;
		for(auto t:edge[top.id]){
			if(dis[t.first] > dis[top.id] + t.second){
				dis[t.first] = dis[top.id] + t.second;
				q.push({t.first,dis[t.first]});
			}
		}
	}
	
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
}