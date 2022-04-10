#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
#define maxn 5414
#define __INF 0x3f3f3f3f
int n,m,tu,tv,tw,anss;
std::vector<int>v[maxn];
std::queue<int> q;
int fn[maxn];
int indu[maxn],cdu[maxn];
int maxxx(int x,int y){return x>y?x:y;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fn[i]=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&tu,&tv);
		v[tu].push_back({tv});
		indu[tv]++;
		cdu [tu]++;
	}

	for(int i=1;i<=n;i++)
		if(indu[i]==0)
			q.push(i),
			fn[i]=1;
		
	
	while(!q.empty()){
		int tn = q.front();
		q.pop();
		for(auto i:v[tn]){
			fn[i]=(fn[i]+fn[tn])%80112002;
			if(--indu[i]==0)			
				q.push(i);	
		}
	}
	
	for(int i=1;i<=n;i++)
		if(cdu[i]==0)
			anss+=(fn[i]%80112002),
			anss%=80112002;
		
	printf("%d",anss);
	return 0;
}