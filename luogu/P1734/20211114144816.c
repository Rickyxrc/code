#include<stdio.h>
#define maxn 1005
int dp[maxn],n,t,v[maxn],w[maxn];
int max(int a,int b){return a>b?a:b;}
int getysh(int x){
	int ans=0;
	for(int i=1;i<x;i++){
		if(!(x%i))
			ans+=i;
	}
	return ans;
}
int main(){
	scanf("%dd",&n);
	for(int i=0;i<n;i++){
		v[i]=getysh(i+1);
		w[i]=i+1;
	}
	for(int i=0;i<n;i++)
		for(int j=w[i];j<=n;j++)
			dp[j] = max(
				dp[j],
				dp[j-w[i]]+v[i]
			);
	printf("%d",dp[n]);
	return 0;
}