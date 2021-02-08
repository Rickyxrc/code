#include<bits/stdc++.h>
using namespace std;
bool k[10000];
int n,le,cnt=0;
int main(){
	cin>>le>>n;
	int l,r;
	for(int i=1;i<=n;i++){
		cin>>l>>r;
		for(int s=l;s<=r;s++)
            if(k[s]==0)
				k[s]=1,cnt++;
	}
	cout<<le-cnt+1;
	return 0;
}