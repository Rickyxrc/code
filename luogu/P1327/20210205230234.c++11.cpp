#include<bits/stdc++.h>
using namespace std;
const int maxn=100005; 
map<int,int>k;
int a[maxn],b[maxn],ans,tp;
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],
		b[i]=a[i],
		k[a[i]]=i;
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
		if(b[i]!=a[i])
			ans++,
			tp=k[b[i]],
			k[a[i]]=tp,
			a[tp]=a[i];
	cout<<ans;
	return 0; 
}