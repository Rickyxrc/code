#include<stdio.h>
#include<vector>
#define maxn 100005
using namespace std;
vector<int> v[maxn];
int mxeach[maxn];
int n,m,tp1,tp2;
void dfs(int now,int source){
	if(mxeach[now])
		return;
	mxeach[now]=source;
	for(vector<int>::iterator it=v[now].begin();it<v[now].end();it++)
		dfs(*it,source);
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&tp1,&tp2);
		if(tp1==tp2)
			continue;
		v[tp2].push_back(tp1);
	}
	for(int i=n;i;i--)
		dfs(i,i);
	for(int i=1;i<=n;i++)
		printf("%d ",mxeach[i]);
	return 0;
}