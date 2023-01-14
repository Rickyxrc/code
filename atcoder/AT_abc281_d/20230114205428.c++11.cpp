#include<stdio.h>
#include<memory.h> 

#define int long long

int n,k,d,t,dp[107][107][107];

int amod(int num){
	return (num%d+d)%d;
}

inline int max(int a,int b){
	return a>b?a:b;
}

signed main(){
	scanf("%lld%lld%lld",&n,&k,&d);
	
	memset(dp,-0x3f,sizeof dp);
	dp[0][0][0] = 0;
	
	for(int i=1;i<=n;i++){
		scanf("%lld",&t);
		for(int j=0;j<=k;j++)
			for(int k=0;k<d;k++){
				dp[i][j][k] = max(
					dp[i][j][k],
					dp[i-1][j][k]
				);
				if(j) 
					dp[i][j][k] = max(
						dp[i][j][k],
						dp[i-1][j-1][amod(k-t)]+t
					);
			}
	}
	
	printf("%lld",(dp[n][k][0]<0?-1:dp[n][k][0]));
	return 0;
}