#include<stdio.h>
#include<vector>
#include<cmath>
#include<ctime>
#include<memory.h>

inline double min(double a,double b){
	return a<b?a:b;
}

struct bset{
	int t;
	bset(){t=0;}
	bset(int tp){t=tp;}
	bset set(int i,bool status){
		if(status==1)
			return t|(1<<i);
		if(status==0)
			return t&(~(1<<i));
	}
	bset get(int i){
		return t&(1<<i);
	}
	void print2bit(){
		for(int i=6;~i;i--)
			putchar(48+bool(t&(1<<i)));
		putchar('\n');
	}
	operator int(){
		return t;
	}
};

bset basee(0);

double dist(std::pair<double,double> a,std::pair<double,double> b){return sqrt(double(a.first-b.first)*(a.first-b.first) + double(a.second-b.second)*(a.second-b.second));}

double dps[17][32770],ans;

std::pair<double,double> v[17],Base={0,0};
int n,t1,t2;

int main(){
	scanf("%d",&n);
//	printf("%d",bset(n).print2bit());
	
	for(int i=0;i<n;i++)	
		scanf("%lf%lf",&v[i].first,&v[i].second);
	
	memset(dps,127,sizeof(dps));
//	printf("%lf",dps[0][0]);

	for(int i=0;i<n;i++)
	{
		dps[i][basee.set(i,1)]=dist(Base,v[i]);
//		printf("%d,%d = %lf\n",i,basee.set(i,1),dist(Base,v[i]));
	}
		
	for(int k=0;k<(1<<n);k++)
		for(int i=0;i<n;i++){
			if(bset(k).get(i)==0)
				continue;
			for(int j=0;j<n;j++)
			{
				if(i==j || (bset(k).get(j))==0)
					continue;
				dps[i][k] = min(dps[i][k],dist(v[i],v[j])+dps[j][bset(k).set(i,0)]);
			} 
		}

	ans=1e12;
	for(int i=0;i<n;i++)
	{
		ans=min(ans,dps[i][(1<<n)-1]);
	}
	printf("%.2lf",ans);
}