#include<bits/stdc++.h>
using namespace std;
int n[100001];
int main(){
    int a;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>n[i];
    }
    sort(n+1,n+a+1);
    for(int i=1;i<=a;i++){
        cout<<n[i]<<" ";
    }
    return 0;
}