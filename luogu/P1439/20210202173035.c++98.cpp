#include<bits/stdc++.h>
using namespace std;
int lsh[100001],tpp[100001];
int n,a[100001],f[100001];
int main(){
	int n,tp;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tp;
		lsh[tp]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>tpp[i];
		a[i]=lsh[tpp[i]];
	}
	int ans=1; 
	f[1]=a[1];
	for(int i=2;i<=n;++i){
		int l=1,r=ans,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[i]<=f[mid])r=mid-1;
			else l=mid+1;
		}
		f[l]=a[i];
		if(l>ans)
		    ++ans;
	}
	cout<<ans<<endl;
	return 0;
}