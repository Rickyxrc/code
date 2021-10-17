#include<stdio.h>
int k[200005],tp,dp[200005],ans=1<<31;
int main(){
	scanf("%d",&tp);
	for(int i=1;i<=tp;i++)
		scanf("%d",&k[i]);
	dp[tp] = k[tp];
	for(int i=tp-1;i>=1;i--)
		dp[i] = k[i] + (dp[i+1]>0?dp[i+1]:0);
	for(int i=1;i<=tp;i++)
		ans = (ans < dp[i] ? dp[i] : ans);
	printf("%d",ans);
	return 0;
}