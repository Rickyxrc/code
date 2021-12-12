#include<stdio.h>
#include<vector>
#include<cmath>
#include<memory.h>
#define maxn 105
std::vector<std::pair<int,int> >d;
std::vector<std::pair<int,double> >edge[maxn];
double slen[maxn];
int n,tp1,tp2,m,st,ed;
double tpd;
double dgr(int x,int y,int xx,int yy){
	return 
		double(sqrt(
			(double(x)-double(xx))*(double(x)-double(xx)) +
			(double(y)-double(yy))*(double(y)-double(yy))
		));
}
int main(){
	d.push_back({0,0});
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&tp1,&tp2),
		d.push_back({tp1,tp2});
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&tp1,&tp2),
		tpd = dgr(d[tp1].first,d[tp1].second,d[tp2].first,d[tp2].second),
		edge[tp1].push_back({tp2,tpd}),
		edge[tp2].push_back({tp1,tpd});
	scanf("%d%d",&st,&ed);
	
	for(int i=1;i<=n;i++)	
		slen[i] = 2147483647.00;
	slen[st]=0;
	
	for(int rounds=1;rounds<n;rounds++){
		for(int i=1;i<=n;i++)
			for(std::vector<std::pair<int,double> >::iterator it=edge[i].begin();
				it<edge[i].end();it++){
					if( slen[it->first] > slen[i] + it->second )
						slen[it->first] = slen[i] + it->second ;
				}
				
	}
	
	printf("%.2lf",slen[ed]);
	
	return 0;
}
//
//template <class T,class TT>
//struct pair<T,TT>{
//	T first;
//	TT second;
//};