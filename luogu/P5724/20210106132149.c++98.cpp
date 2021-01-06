#include<bits/stdc++.h>
using namespace std;
int main(){
    short x;
    cin>>x;
    short f,mx=-1,mn=1001;
    for(int i=1;i<=x;i++){
        cin>>f;
        mx=max(f,mx);
        mn=min(f,mn);
    }
    cout<<mx-mn;
    return 0;
}