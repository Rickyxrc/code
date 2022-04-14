#include<stdio.h>
#include<vector>
#include<queue>
#define maxn 105
std::vector<std::pair<int,int> > v[maxn];
std::queue<int> q;
int us[maxn],indu[maxn],val[maxn],cdu[maxn];
int n,p,tu,tv,tw,f=1;
int Relu(int i){
	if(i>0)
		return i;
	return 0;
}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)	
		scanf("%d%d",&val[i],&us[i]);
	for(int i=1;i<=p;i++){
		scanf("%d%d%d",&tu,&tv,&tw);
		v[tu].push_back({tv,tw});
		indu[tv]++;
		cdu [tu]++;
	}
	for(int i=1;i<=n;i++){
		if(indu[i]==0)
			q.push(i);
	}
	while(!q.empty()){
		int tn = q.front();
		q.pop();
		for(auto i:v[tn]){
			val[i.first] += val[tn]*i.second;
			if(--indu[i.first]==0)
				val[i.first] -= us[i.first],
				val[i.first] = Relu(val[i.first]),
				q.push(i.first);
		}
	}
	for(int i=1;i<=n;i++)
		if(cdu[i]==0&&val[i])
			f=0,
			printf("%d %d\n",i,val[i]);
	if(f)
		printf("NULL");
	return 0;
}