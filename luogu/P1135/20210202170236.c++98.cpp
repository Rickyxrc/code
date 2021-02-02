#include<bits/stdc++.h>
using namespace std;
bool book[201];
int r[201],n,ans=2147483647;
void dfs(int flr,int b,int step){
    if(flr==b){
        ans=min(ans,step);
        return;
    }
    if(flr<=0||flr>n||book[flr]||r[flr]==0||step+1>ans)
        return; 
    book[flr]=1;
    dfs(flr+r[flr],b,step+1);
    if(step+1>ans)
        return;
    dfs(flr-r[flr],b,step+1);
    book[flr]=0;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    int a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
        cin>>r[i];
    dfs(a,b,0);
    if(ans==2147483647)
        cout<<"-1";
    else
        cout<<ans;
    return 0;
}