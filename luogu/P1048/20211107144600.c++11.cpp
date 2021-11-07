#include<stdio.h>
#define maxn 4096
int dp[maxn],n,t,v[maxn],w[maxn];
int max(int a,int b){return a>b?a:b;}
int main(){
	scanf("%d%d",&t,&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",w+i,v+i);
	for(int i=0;i<n;i++)
		for(int j=t;j>=w[i];j--)
			dp[j] = max(
				dp[j],
				dp[j-w[i]]+v[i]
			);
	printf("%d",dp[t]);
	return 0;
}