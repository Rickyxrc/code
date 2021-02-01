#include<bits/stdc++.h>
using namespace std;
int main(){
    string m;
    cin>>m;
    for(int i=0;i<m.length();i++)
        if(m[i]>='a'&&m[i]<='z')
            cout<<char(m[i]-'a'+'A');
        else
            cout<<m[i];
    return 0;
}