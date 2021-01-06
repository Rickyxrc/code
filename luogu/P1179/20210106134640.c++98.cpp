#include<bits/stdc++.h>
using namespace std;
int con(int x,int n){
    int vl=0;
    while(x){
        if(x%10==n){
            vl++;
        }
        x/=10;
    }
    return vl;
}
int main(){
    int l,r,s=0;
    cin>>l>>r;
    for(int i=l;i<=r;i++)
        s+=con(i,2);
    cout<<s;
    return 0;
}