#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define maxn 114514
#define inf 0x3f3f3f3f
int n,m,tu,tv,tw,td,c;
vector<pair<int,int> >v[maxn];
queue<int> q;
map<pair<int,int>,int >mp;
int indu[maxn],sdays[maxn];
int maxxx(int x,int y){return x>y?x:y;}
int main(){
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++)
		cin>>sdays[i];
	for(int i=1;i<=c;i++){
		cin>>tu>>tv>>tw;
		v[tu].push_back(pair<int,int>({tv,tw}));
		indu[tv]++;
	}

	for(int i=1;i<=n;i++)
		if(indu[i]==0)
			q.push(i);
	
	while(!q.empty()){
		int tn = q.front();
		q.pop();
		for(int i=0;i<v[tn].size();i++){
			sdays[v[tn][i].first] = 
				max(sdays[tn]+v[tn][i].second,
				sdays[v[tn][i].first]);
				
			if(--indu[v[tn][i].first]==0)				
				q.push(v[tn][i].first);
		}
	}
	
	for(int i=1;i<=n;i++)
		cout<<sdays[i]<<endl;
		
	return 0;
}