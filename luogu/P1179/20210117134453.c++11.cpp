#include<bits/stdc++.h>
using namespace std;
int cnt(long long m){
	int n=0;
	while(m){
		if(m%10==2)
		n++;
		m/=10;
	}
	return n;
	
}
int main(){
	int l,r;
	int ans=0;
	cin>>l>>r;
	for(int i=l;i<=r;i++)
		ans+=cnt(i);
	cout<<ans;
	return 0;
}