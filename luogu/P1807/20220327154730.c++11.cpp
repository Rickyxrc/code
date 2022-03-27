#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
#define maxn 1514
#define __INF 0x3f3f3f3f
int n,m,tu,tv,tw;
std::vector<std::pair<int,int> >v[maxn];
std::queue<int> q;
std::map<std::pair<int,int>,int >mp;
int indu[maxn],tonjuli[maxn];
int maxxx(int x,int y){return x>y?x:y;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		tonjuli[i] = -__INF ;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&tu,&tv,&tw);
		v[tu].push_back({tv,tw});
		indu[tv]++;
	}

	for(int i=1;i<=n;i++){
		tonjuli[i]=-__INF;
		if(indu[i]==0)
			q.push(i);
	}
		
	tonjuli[1]=0;
	
	while(!q.empty()){
//		printf("front = %d\n",q.front());
		int tn = q.front();
//		printf("now tn = %d\n",tn);
		q.pop();
		for(auto i:v[tn]){
//			printf("(f%d,s%d) tn=%d %d %d\n",i.first,i.second,tn,tonjuli[i.first],tonjuli[tn]);
			if(tonjuli[tn] != -__INF)
				tonjuli[i.first] = maxxx(tonjuli[i.first],tonjuli[tn]+i.second);
			if(--indu[i.first]==0)				
				q.push(i.first);
//			for(int i=1;i<=n;i++)
//				printf("%d ",tonjuli[i]);
//			printf("\n");
		}
	}
	
	if(tonjuli[n]==-__INF)
		return !puts("-1");
	else
		printf("%d",tonjuli[n]);
		
	return 0;
}