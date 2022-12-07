#include<stdio.h>
#include<vector>

const int maxn = 500000 + 7;

std::vector<int> edge[maxn];

int fa[maxn],size[maxn],deps[maxn],hson[maxn],topp[maxn],id[maxn],rev[maxn];

int n,m,s,t1,t2,cnt;

void dfs(int index,int fath){
	deps[index] = deps[fath] + 1;
	fa[index] = fath;
	size[index] = 1;
	for(auto k:edge[index]){
		if(k == fath)
			continue;
		dfs(k,index);
		size[index] += size[k];
		if(size[hson[index]] < size[k])
			hson[index] = k;
	}
}

void treecut(int index,int top){
	topp[index] = top;
	id[index] = ++cnt;
	rev[cnt] = index;
	if(hson[index] == 0)return;
	treecut(hson[index],top);
	for(auto k:edge[index])
		if(k != hson[index] && k!= fa[index])
			treecut(k,k);
}

inline int LCA(int i,int j){
	while(topp[i] != topp[j]){
		if(deps[topp[i]] > deps[topp[j]])
			i = fa[topp[i]];
		else
			j = fa[topp[j]];
	}
	return deps[i]<deps[j]?i:j;
}

int main(){
	scanf("%d%d%d",&n,&m,&s);
	
	for(int i=1;i<n;i++)
		scanf("%d%d",&t1,&t2),
		edge[t1].push_back(t2),
		edge[t2].push_back(t1);
	
	dfs(s,s);
	treecut(s,s);
	
	for(int i=1;i<=m;i++)
		scanf("%d%d",&t1,&t2),
		printf("%d\n",LCA(t1,t2));
	
	return 0;
}