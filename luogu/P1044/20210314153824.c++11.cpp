#include<bits/stdc++.h>
using namespace std;
int n,dp[19]={1,1};
int main(){
	cin>>n;
	for(int i=2;i<=n;i++)
		for(int j=0;j<i;j++)
			dp[i]=dp[i]+dp[j]*dp[i-j-1];
	cout<<dp[n];
	return 0;
}