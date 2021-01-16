#include<bits/stdc++.h>
using namespace std;
int main(){
    double step=2;
    double l=2147483648;
    int i=0;
    cin>>l;
    while(l>=0){
        l-=step;
        i++;
        step*=0.98;
    }
    cout<<i;
    return 0;
}