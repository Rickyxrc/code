#include<bits/stdc++.h>
#define MAXN 20000001
using namespace std;
long long dp[MAXN],ans,n;
int main(){
	cin>>n;
	for(int i=n;i;i--){
		dp[i]=(n/i)*(n/i);
		for(int j=i<<1;j<=n;j+=i)dp[i]=dp[i]-dp[j];
		ans+=dp[i]*i;
	}
	cout<<(ans-n*(n+1)/2)/2;
	return 0;
}