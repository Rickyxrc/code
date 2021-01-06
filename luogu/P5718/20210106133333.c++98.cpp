#include<bits/stdc++.h>
using namespace std;
int main(){
    long long x,r;
    cin>>x;
    long long minn=9999999999;
    for(int i=1;i<=x;i++){
        cin>>r;
        minn=min(minn,r);
    }
    cout<<minn;
    return 0;
}