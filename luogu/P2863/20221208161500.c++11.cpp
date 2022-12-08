#include<stdio.h>
#include<vector>

#define maxn 10007

std::vector<int> edge[maxn],edge2[maxn];

int flg[maxn],vis[maxn],res[maxn],size[maxn],cnt1,cnt2,ans;
int n,m,u,v;

void dfs1(int x){
	if(flg[x])return;
	flg[x]=1;
	for(auto s:edge[x])
		dfs1(x);
	vis[++cnt1] = x;
}

void dfs2(int x){
	if(res[x])return;
	res[x] = cnt2;
	size[cnt2]++;
	for(auto t:edge[x])
		dfs2(t);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		edge [u].push_back(v);
		edge2[v].push_back(u);
	}
	
	for(int i=1;i<=n;i++)
		dfs1(i);
	
	for(int i=cnt1;i;i--)
		if(!res[i]){
			cnt2++;
			dfs2(i);
		}
	
//	for(int i=1;i<=n;i++)
//		printf("%d ",res[i]);
		
	for(int i=1;i<=cnt2;i++)
		ans += size[i] > 1;
		
	printf("%d",ans);
	return 0;
}