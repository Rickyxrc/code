#include<iostream>
#include<queue>
#include<vector> 
using namespace std;
int m,n,u,v;
int dis[100005],deagree_in[100005],b[100005],ans;
queue<int>q;
vector<int> edge[100005];
void topsort()
{
	long long i;
	for(i=1;i<=n;i++)if(deagree_in[i]==0)q.push(i);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=0;i<edge[u].size();i++)
		{	
//			printf("123");
			deagree_in[edge[u][i]]--;
			dis[edge[u][i]]=dis[edge[u][i]]+dis[u];			
			if(deagree_in[edge[u][i]]==0)
			{
				q.push(edge[u][i]);
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		edge[u].push_back(v);
		deagree_in[v]++;
		b[u]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(deagree_in[i]==0&&b[i]!=0)
		{
			dis[i]=1;
		}
	}
	topsort();
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			ans=(ans+dis[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}