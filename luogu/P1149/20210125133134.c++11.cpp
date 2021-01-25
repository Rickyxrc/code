#include<bits/stdc++.h>
using namespace std;
int l[10]={6,2,5,5,4,5,6,3,7,6};
int fnum(int r){
    if(!r)
        return 6;
    int ct=0;
    while(r){
        ct+=l[r%10];
        r/=10;
    }
    return ct;
}
int main(){
    int n;
    cin>>n;
    int a,b,c,cnt=0;
    for(a=0;a<=1111;a++)
        for(b=0;b<=1111;b++){
            c=a+b;
            if((fnum(a)+fnum(b)+fnum(c))+4==n)
                cnt++;
        }
    cout<<cnt;
    return 0;
}