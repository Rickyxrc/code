#include<stdio.h>
#include<vector>
#include<string.h>
#define maxn 5555
#define __INF 0x3f3f3f3f
std::vector<std::pair<int,int> > edge[maxn];
int l[maxn],v[maxn];
int n,m,a,b,c,mxlen,ll,fail;
int minnn(int a,int b){return a<b?a:b;}
void fl(int n){
	for(std::vector<std::pair<int,int> >::iterator it = edge[n].begin();
		it < edge[n].end() ; it++){
			if(v[it->first])continue;
			l[it->first] = minnn(l[it->first],it->second);
//			printf("l[%d] = %d\n",it->first,minnn(l[it->first],it->second));
		}
			
}
int fmin(){
	int mn=__INF,mp;
	for(int i=1;i<=n;i++)
		if(!v[i] && mn>l[i])
			mp = i,
			mn = l[i];
	if(mn == __INF)
		fail = 1;
	return mp;
}
void ch(int f,int s){
	v[f] = 1;
	mxlen += s;
}
int main(){
	memset(l,__INF,sizeof(l));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a,&b,&ll),
		edge[a].push_back({b,ll}),
		edge[b].push_back({a,ll});
	
		
	l[1] = 0;
	v[1] = 1;
	fl(1);
	
//	for(int i=1;i<=n;i++)
//		printf("%d ",l[i]);
//	printf("\n");

	for(int i=1;i<=n-1;i++){
		fail = 1;
//		printf("st\n");
		for(int i=1;i<=n;i++){
			if(v[i])continue;
//			printf("look %d|%d\n",i,l[i]);
			if(l[i]!=__INF){fail=0;break;}
		}
		if(fail){printf("orz");return 0;}
		int mnod = fmin();
		ch(mnod,l[mnod]);
		fl(mnod);
	}
	
	printf("%d",mxlen);
	return 0;
} 