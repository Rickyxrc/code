#include<stdio.h>
#include<vector>
#include<memory.h>

#define maxn 500007

std::vector<int> edge[maxn];

int n,m,s,x,y,liancnt;

int deps[maxn],fa[maxn],size[maxn],hson[maxn],top[maxn],rev[maxn],id[maxn];

void first_dfs(int index,int fath){
	deps[index] = deps[fath]+1;
	fa[index] = fath;
	size[index] = 1;
	for(auto s:edge[index]){
		if(s == fath)continue;
		first_dfs(s,index);
		size[index] += size[s];
		if(size[hson[index]] < size[s])
			hson[index] = s;
	}
}

void treecut(int index,int topp){
	top[index] = topp;
	id[index] = ++liancnt;
	rev[liancnt] = index;
	if(hson[index] == 0)return;
	treecut(hson[index],topp);
	for(auto s:edge[index])
		if(s!=hson[index] && s!=fa[index])
			treecut(s,s);
}

inline int lca(int a,int b){
	while(top[a] != top[b]){
		if(deps[top[a]] > deps[top[b]])
			a = fa[top[a]];
		else
			b = fa[top[b]];
	}
	return deps[a]<deps[b] ? a:b;
}

int main(){
	scanf("%d%d%d",&n,&m,&s);
	
	for(int i=1;i<n;i++)	
		scanf("%d%d",&x,&y),
		edge[x].push_back(y),
		edge[y].push_back(x);
	
	memset(deps,0x3f,sizeof(deps));
//	memset(size,0x3f,sizeof(size));
	deps[s]=0;
	
	first_dfs(s,s);
	treecut(s,s);
	
	for(int i=1;i<=m;i++)	
		scanf("%d%d",&x,&y),
		printf("%d\n",lca(x,y));
	return 0;
}
/*
5 3 3
3 2
3 5
5 1
2 4
1 4
2 3
5 3

4 2 1
1 2
2 3
3 4

*/