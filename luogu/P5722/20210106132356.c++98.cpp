#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long x;
    cin>>x;
    unsigned long long s=0;
    for(unsigned long long i=1;i<=x;i++){
        s+=i;
    }
    cout<<s;
    return 0;
}