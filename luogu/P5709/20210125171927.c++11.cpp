#include<bits/stdc++.h>
using namespace std;
int main(){
    double m,t,s;
    cin>>m>>t>>s;
    if(m-ceil(s/t)<0)
        cout<<0;
    else cout<<m-ceil(s/t);
    return 0;
}