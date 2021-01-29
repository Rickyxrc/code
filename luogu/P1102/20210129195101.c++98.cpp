#include<bits/stdc++.h>
using namespace std;
map<long long,int>m=map<long long,int>();
map<long long,int>::iterator it;
int k[200001];
int main(){
	long long n,c,tp,cnt=0;
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>tp;
		if(m.find(tp)==m.end()){
			m[tp]=1;
		}
		else
			m[tp]=m[tp]+1;
		k[i]=tp;
	}
	for(int i=1;i<=n;i++)
		cnt+=m[k[i]+c];
	cout<<cnt;
	return 0;
}