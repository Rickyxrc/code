#include<bits/stdc++.h>
using namespace std;
int main(){
    double a,b,c;
    cin>>a>>b>>c;
    double ans=0.25*sqrt((a+b+c)*(a+b-c)*(a-b+c)*(-a+b+c));
    cout<<fixed<<setprecision(1)<<ans;
    return 0;
}