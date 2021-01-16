#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int tp;
    for(int i=1;i<=n;i++){
        cin>>tp;
        if(tp==0)
            continue;
        if(i==1&&tp>0);
        else if(tp<0)cout<<"-";
        else if(tp>0)cout<<"+";
        if(abs(tp)!=1)
            cout<<abs(tp);
        //if(i!=n)
            cout<<"x";
        if((n-i+1)!=1)cout<<"^"<<n-i+1;
    }
    cin>>tp;
    if(tp==0)
        return 0;
    if(tp>=0)cout<<"+";
    else cout<<"-";
    cout<<abs(tp);
    return 0;
}