#include<bits/stdc++.h>
using namespace std;
bool bk[22]={0},f=1;
int st[25]={0},top=1;
void dfs(int n,int r);
void dfs(int n,int r,int step);
int main(){
    int n,r;
    cin>>n>>r;
    if(r==0)
        return 0;
    dfs(n,r);
    return 0;
}
void dfs(int n,int r){
    for(int i=1;i<=n;i++){
        st[top++]=i;
        bk[i]=1;
        dfs(n,r,2);
        bk[i]=0;
        top--;
    }
    return;
}
void dfs(int n,int r,int step){
    //cout<<"dfs("<<step<<")"<<endl;
    if(step>r){
        if(!f)cout<<endl;
        else f=0;
        for(int i=1;i<top;i++)
            cout<<setw(3)<<st[i];
        return;
    }
    for(int i=st[top-1];i<=n;i++){
        if(bk[i]==0){
        st[top++]=i;
        bk[i]=1;
        dfs(n,r,step+1);
        bk[i]=0;
        top--;
        }
    }
    return;
}