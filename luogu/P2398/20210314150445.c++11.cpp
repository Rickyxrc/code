#include<bits/stdc++.h>
#define MAXN 1000001
using namespace std;
long long dp[MAXN],ans,n;
int main(){
	cin>>n;
	for(int i=n;i>0;i--){
		dp[i]=(n/i)*(n/i);
		for(int j=i*2;j<=n;j+=i)dp[i]=dp[i]-dp[j];
		ans+=dp[i]*i;
	}
	cout<<ans;
	return 0;
}