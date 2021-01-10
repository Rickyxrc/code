#include<bits/stdc++.h>//header file
using namespace std;//namespace
long long dp[200001];
int main(){//main
	long long n;
	long long tmp,maxx=-9999999999;
	cin>>n;
	cin>>tmp;
	dp[1]=tmp;
	for(int i=2;i<n+1;i++){
		cin>>tmp;
        dp[i]=max(tmp+dp[i-1],tmp);
        maxx=max(maxx,dp[i]);
//		cout<<dp[i]<<" ";
	}
	cout<<maxx;
	return 0;//return value 0
}
