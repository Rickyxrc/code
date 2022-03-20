#include<stdio.h>
#include<string.h>
#include<cmath>
#define maxn 1050
#define __INF 9223372036854775807ll
long long edge[maxn][maxn];
long long l[maxn],v[maxn],xs[maxn],ys[maxn];
int n,m,a,b,c,ll,fail;
double mxlen = 0.0;
long long minnn(long long a,long long b){return a<b?a:b;}
void fl(long long s){
	for(long long i=1;i<=n;i++){
		if(v[i])continue;
		l[i] = minnn(l[i],edge[s][i]);
	}
}
long long fmin(){
	long long mn=__INF,mp=0;
	for(int i=1;i<=n;i++)
		if(!v[i] &&(mp == 0 || mn>l[i])) 
			mp = i,
			mn = l[i];
	return mp;
}
void ch(int f,long long s){
	v[f] = 1;
	mxlen += sqrt(s);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		l[i]=__INF;
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&xs[i],&ys[i]);
	for(int i=1;i<=m;i++)
		scanf("%lld%lld",&a,&b),
		edge[a][b]=-1,
		edge[b][a]=-1;
		 
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(edge[i][j]==-1)
				edge[j][i] = edge[i][j] = 0;
			else
				edge[j][i] = edge[i][j] = (((xs[i])-(xs[j]))*((xs[i])-(xs[j]))+((ys[i])-(ys[j]))*((ys[i])-(ys[j])));
		}
	
	l[1] = 0;	
	v[1] = 1;
	fl(1);

	for(int i=1;i<=n-1;i++){
		int mnod = fmin();
		ch(mnod,l[mnod]);
		fl(mnod);
	}
	printf("%.2f",mxlen);
	return 0;
} 