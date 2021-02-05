#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
long long tp; 
unordered_map<long long,int>mp;
unordered_map<int,long long>mpp;
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		register long long n;
		cin>>n;
		mp=unordered_map<long long,int>();
		mpp=unordered_map<int,long long>();
		for(int i=1;i<=n;i++){
			cin>>tp;
			mp[tp]++;
			if(mp[tp]==1)
				mpp[i]=tp;
		}
		for(int i=1;i<=n;i++){
			if(mpp.find(i)!=mpp.end())
				cout<<mpp[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}