#include <bits/stdc++.h>
#define N 100001
using namespace std;
int n,m,cnt[N],lowidx[N],inde,res;
bool vised[N],flag[N];
vector<int> edge[N];
void func(int u,int fath){
	    vised[u]=true;
	    lowidx[u]=cnt[u]=++inde;
	    int child=0;
	    for(auto v:edge[u]){
	    if(!vised[v]){
	        child++;
	        func(v,u);
	        lowidx[u]=min(lowidx[u],lowidx[v]);
	        if(fath!=u&&lowidx[v]>=cnt[u]&&!flag[u])
	            flag[u]=true,
	            res++;
	    }else
	        if(v!=fath)
	            lowidx[u]=min(lowidx[u],cnt[v]);
	}
	if (fath==u&&child>=2&&!flag[u]){
	    flag[u]=true,
	    res++;
	}
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if(!vised[i]){
            inde=0;
            func(i,i);
        }
    cout<<res<<endl;
    for (int i=1;i<=n;i++)
        if (flag[i])
            cout<<i<<" ";
    return 0;
}