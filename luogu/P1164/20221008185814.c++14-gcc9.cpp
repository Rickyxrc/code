#include<stdio.h>
#define maxn 107
#define maxm 10007
int dp[maxn][maxm],val[maxn],n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",val+i);
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++){
			if(j==val[i]) //一道菜刚好花完钱
				//方案数量+1 (只点这道菜) 
				dp[i][j] = dp[i-1][j]+1;
			else if(j>val[i]) //钱比这道菜多 
				//方案数量 = 只点这道菜+不点这道菜 
				dp[i][j] = dp[i-1][j-val[i]] + dp[i-1][j];
			else if(j<val[i]) //钱比这道菜少 
				//方案数量 = 不点这道菜 
				dp[i][j] = dp[i-1][j];
		}
	printf("%d",dp[n][m]);
	return 0;
} 