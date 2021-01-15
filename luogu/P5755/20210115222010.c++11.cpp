#include<bits/stdc++.h>
using namespace std;
map<string,bool>mapp;
map<string,bool>::iterator it;
int main(){
    char m;
    string s;
    unsigned long long num=1;
    while(cin.get(m)){
        if(m!='\r'&&m!='\n')
            s+=m;
        if(m=='\r'||m=='\n'){
            s=string();
            continue;
        }
        //cout<<s<<"|"<<endl;
        it=mapp.find(s);
        if(it==mapp.end()){
            //cout<<s<<"]"<<endl;
            mapp[s]=1;
            num++;
        }
    }
    cout<<num;
    return 0;
}