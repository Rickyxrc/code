#include<bits/stdc++.h>
using namespace std;
struct AK{
	int data;
	int n;
	int index;
}dt[1001];
int tt;
map<int,int>mp=map<int,int>();
inline bool cp1(AK i,AK j){
	if(i.n!=j.n)
		return i.n>j.n;
	return i.index<j.index;
}
int main(){
	int n,tp,c;
	cin>>n>>c; 
	for(int i=1;i<=n;i++){
		cin>>tp;
		if(!mp[tp])
			tt++,
			mp[tp]=tt,
			dt[tt].data=tp,
			dt[tt].n++,
			dt[tt].index=i;
		else
			dt[mp[tp]].n++;	
	}
	sort(dt+1,dt+n+1,cp1);
	for(int i=1;i<=tt;i++)
		for(int j=1;j<=dt[i].n;j++)
			cout<<dt[i].data<<" ";
	return 0;
}