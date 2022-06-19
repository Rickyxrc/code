#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int ans=0,n,tp;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>tp,
		ans^=tp; 
	cout<<ans;
	return 0;
}