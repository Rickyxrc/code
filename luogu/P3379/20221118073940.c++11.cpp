#include<iostream> 
#include<vector>
using namespace std;
#define maxn 500007

std::vector<int> edge[maxn];

int depth[maxn],fa[maxn],size[maxn],hson[maxn],top[maxn],id[maxn],rev[maxn],cnt;

void pre_process(int index,int fath){
	depth[index] = depth[fath]+1;
	fa[index] = fath;
	size[index] = 1;
	for(auto s:edge[index]){
		if(s!=fath){
			pre_process(s,index);
			size[index] += size[s];
			if(size[hson[index]] < size[s])
				hson[index] = s;
		}
	}
}

void treecut(int index,int topp){
	rev[index] = ++cnt;
	id[cnt] = index;
	top[index] = topp;
	if(hson[index] == 0)
		return;
	treecut(hson[index],topp);
	for(auto s:edge[index]){
		if(s!=fa[index] && s!=hson[index])
			treecut(s,s);
	}
}

int lca(int a,int b){
	while(top[a] != top[b]){
//		printf("### %d %d %d %d\n",a,b,depth[top[a]],depth[top[b]]);
		if(depth[top[a]] > depth[top[b]])
			a = fa[top[a]];
		else
			b = fa[top[b]];
	}
	if(depth[a] > depth[b])
		return b;
	return a;
}

int n,m,s,x,y;

int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	
	depth[s]=1;
	pre_process(s,s);
	treecut(s,s);
	
	for(int i=1;i<=m;i++){	
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}