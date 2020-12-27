#include<bits/stdc++.h>
using namespace std;
map<int,int>::iterator it;
map<int,int>m;
int main(){
	int n,q,tmp;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>tmp;
		it=m.find(tmp);
		if(it==m.end())
			m[tmp]=i;
	}
	for(int i=1;i<q;i++){
		int x;
		cin>>x;
		it=m.find(x);
		if(it!=m.end())
			cout<<it->second<<" ";
		else
			cout<<"-1 ";
	}
	int x;
		cin>>x;
		it=m.find(x);
		if(it!=m.end())
			cout<<it->second;
		else
			cout<<"-1";
	return 0;
}