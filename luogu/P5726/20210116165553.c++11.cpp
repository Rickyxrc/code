#include<bits/stdc++.h>
using namespace std;
int tp[1001];
int main(){
    double av=0.0;
    int n;
    int mx=-1,mn=11;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tp[i];
        mx=max(mx,tp[i]);
        mn=min(mn,tp[i]);
    }
    for(int i=1;i<=n;i++){
        av+=tp[i];
    }
    av-=mx;
    av-=mn;
    av/=(n-2);
    cout<<fixed<<setprecision(2)<<av;
    return 0;
}