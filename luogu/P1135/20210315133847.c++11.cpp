#include<bits/stdc++.h>
#define N 201
using namespace std;
bool k[N];
bool f[N];
struct Int{
	int k;
	int step;
};
queue<Int> queu;
int main(){
	int n,a,b,Tp;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
		scanf("%d",&k[i]);
	queu.push({a,0});
	f[a]=1;
 	int j,r;
	while(queu.size()){
		j=queu.front().k;
		if(j==b){
			cout<<queu.front().step;
			return 0;
		}
		//cout<<j<<"->";
		r=j+k[j];
		//cout<<"("<<k[j]<<","<<r<<")";
		if(((r)<=n)&&(f[r]==0)&&r<=n)
			queu.push({r,queu.front().step+1}),
			f[r]=1;
		r=j-k[j];
		//cout<<"("<<r<<")";
		if((r<=n)&&(f[r]==0)&&r>=1)
			queu.push({r,queu.front().step+1}),
			f[r]=1;
		queu.pop();
	}
	cout<<-1;
	return 0;
}