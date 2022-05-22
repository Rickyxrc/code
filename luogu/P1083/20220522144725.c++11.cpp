#include<stdio.h>
//#define __SINGAL_DEBUG
#define maxn 1000007
#define int long long
int k[maxn];
int mxk[maxn];
int cache[maxn];
int ip1[maxn],ip2[maxn],ip3[maxn];
int n,m,r,f,t,cs,ans=4154113,num;
int min(int ii,int jj){return ii<jj?ii:jj;}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",mxk+i);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",ip1+i,ip2+i,ip3+i);
		k[ip2[i]]+=ip1[i];
		k[ip3[i]+1]-=ip1[i];
//		#ifdef __SINGAL_DEBUG
//		for(int __tp=1;__tp<=n;__tp++)
//			printf(";%d;",k[__tp]);
//		printf("\n");
//		for(int __tp=1;__tp<=n;__tp++)
//			printf(";%d;",mxk[__tp]);
//		printf("\n");
//		#endif
	}
	for(int tt=1;tt<=n;tt++){
		k[tt]+=k[tt-1];
		if(k[tt]>mxk[tt]){
			num=k[tt];
			for(int tp=m;tp>=1;tp--){
				if(ip2[tp]<=tt&&ip3[tp]>=tt)
					num-=ip1[tp];
				if(num<=mxk[tt]){
					ans = min(ans,tp);
					break;
				}
			}
		}
	}
	if(ans==4154113)
		printf("0");
	else
		printf("-1\n%d",ans);
		
	return 0;
}