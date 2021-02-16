#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	unsigned long long t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n==1)
			cout<<1<<endl;
		else if(!n)
			cout<<0<<endl;
		else
			cout<<n*(n-1)<<endl;
	}
	return 0;
}