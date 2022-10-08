#include<stdio.h>
#include<memory.h>
#define maxn 207
int vals[maxn][maxn],dp[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
//			printf("%d - %d;\n",i,j),
			scanf("%d",&vals[i][j]);
	
	memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	
//	for(int k=1;k<=n;k++)
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(dp[i] + vals[i][j] < dp[j])
				dp[j] = dp[i] + vals[i][j];
	
	printf("%d",dp[n]);
}