#include<bits/stdc++.h>
#define N 1001
using namespace std;
bool rd[N][N];
unsigned short m[N];
bool book[N];
bool dfs(int n,int mx){
	for(int i=1;i<=mx;i++){
		if((book[i]==0)&&rd[n][i]){
			book[i]=1;
			if((m[i]==0)||dfs(m[i],mx)){
				m[i]=n;
				return true;
			}
		}
	}
	return false;
}
int main(){
	int l,r,n,tpl,tpr,ans=0;
	cin>>l>>r>>n;
	for(int i=1;i<=n;i++){
		cin>>tpl>>tpr;
		rd[tpl][tpr]=1;
	}
	for(int i=1;i<=max(l,r);i++){
		memset(book,0,sizeof(book));
		if(dfs(i,max(l,r)))
			ans++;
	}
	cout<<ans;
	return 0;
}