#include<bits/stdc++.h>
using namespace std;
int main(){
    int num=1;
    int a,n,tp,x=1;
    cin>>n;
    cin>>tp;
    for(int i=1;i<n;i++){
        cin>>a;
        if(a==tp+1)
            x++;
        else
            x=1;
        //cout<<x<<endl;
        tp=a;
        num=max(x,num);
    }
    cout<<num;
    return 0;
}