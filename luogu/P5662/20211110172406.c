#include<stdio.h>
#include<string.h>
#define maxn 101
#define maxv 10001
int t,n,m,ans,dayans;
int prices[maxn][maxv],dp[maxv];
int max(int a,int b){return a>b?a:b;}
int main(){
	scanf("%d%d%d",&t,&n,&ans);
	for(int i=1;i<=t;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&prices[i][j]);
		
	for(int times=1;times<=t;times++){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int j=prices[times][i];j<=ans;j++){
				dp[j] = max(
					dp[j],
					dp[j - prices[times][i] ] + (prices[times+1][i] - prices[times][i])
				);
			}
		ans=ans+dp[ans];
	}
	printf("%d",ans);
	return 0;
}