#include<stdio.h>
#define maxn 57
#define maxv 407
#define maxm 407
int vmx,mmx,n,v[maxn],m[maxn],val[maxn],dp[maxm][maxv];
inline int mmaxx(int a,int b){return a>b?a:b;}
int main(){
	scanf("%d%d%d",&vmx,&mmx,&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&v[i],&m[i],&val[i]);
	
	for(int i=1;i<=n;i++)
		for(int j=vmx;j>=v[i];j--)
			for(int t=mmx;t>=m[i];t--)
				dp[j][t]=mmaxx(dp[j][t],dp[j-v[i]][t-m[i]]+val[i]);//状态转移方程
	printf("%d",dp[vmx][mmx]);
	return 0;
}