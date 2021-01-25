#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int e,f;
    e=c-a;
    f=d-b;
    while(f<0){
        f+=60;
        e--;
    }
    cout<<e<<" "<<f;
    return 0;
}