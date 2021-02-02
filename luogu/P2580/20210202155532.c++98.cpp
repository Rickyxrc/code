#include<bits/stdc++.h>
using namespace std;
map<string,bool>k;
map<string,bool>rp;
int n;
string st;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>st;
        k[st]=1;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>st;
        if(k.find(st)!=k.end())
            if(rp.find(st)!=rp.end())
                cout<<"REPEAT"<<endl;
            else{
                cout<<"OK"<<endl;
                rp[st]=1;
            }
        else
            cout<<"WRONG"<<endl;
    }
}