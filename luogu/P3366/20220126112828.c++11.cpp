#include<stdio.h>
#include<algorithm>
#define maxn 5050
int k[maxn];
struct node{
	int f,t,k;
}graph[200005];
int cnt=0; 
bool cmp(node i,node j){
	return i.k<j.k;
}
void init(int n){
	for(int i=1;i<=n;i++)
		k[i] = i;
}
int getf(int n){
	return k[n] = (k[n] == n ? k[n] : getf(k[n]));
}
void merge(int i,int j){
	i = getf(i);
	j = getf(j);
	k[i] = j;
}
bool equal(int i,int j){
	return getf(i) == getf(j);
}
int n,m,t1,t2,t3,edge,i,ans;
int main(){
	scanf("%d%d",&n,&m);
	init(m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&t1,&t2,&t3),
		graph[++cnt] = {t1,t2,t3};
	std::sort(graph+1,graph+1+m,cmp);
	i = 1;
	while(1){
		if(edge == n-1)
			break;
		if(i>m){
			printf("orz");
			return 0;
		}
		if(!equal(graph[i].f,graph[i].t)){
			edge++;
			ans+=graph[i].k;
			merge(graph[i].f,graph[i].t);
		}
		i++;
	}
	printf("%d",ans);
	return 0;
}