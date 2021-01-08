#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    float n=0.0;
    cin>>a>>b;
    n+=a;
    n+=float(b)/10;
    cout<<floor(n/1.90);
    return 0;
}