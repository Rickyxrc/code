#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
char s[100];
int n[28],l=0;
char map[1000001][27];
int main(){
    for(int i=0;i<4;i++){
        gets(s);
        l=strlen(s);//
        for(int j=0;j<l;j++){
            if(s[j]<='Z'/**/&&/**/s[j]>='A')
            n[s[j]-'A']++;
        }
    }
    int max=n[0];
    for(int i=0;i<26;i++){
        if(n[i]>max) max=n[i];
    }
    for(int i=0;i<27;i++){
        map[0][i]='A'+i;
        for(int j=1;j<=n[i];j++)
            map[j][i]='*';
    }
    for(int i=max;i>=0;i--){
        for(int j=0;j<26;j++){
            /**/if(map[i][j])cout<<map[i][j];
            /**/else cout<<" ";
            if(/**/j<25)cout<<" ";
        }
        if(i>0)cout<<endl;
    }
}