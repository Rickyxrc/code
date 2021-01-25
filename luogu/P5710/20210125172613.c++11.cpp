#include<bits/stdc++.h>
using namespace std;
inline bool f(int k){return !(k%2);}
inline bool s(int r){return r>4&&r<=12;}
int main(){
    int n;
    cin>>n;
    cout<<(f(n)&&s(n))<<" "<<(f(n)||s(n))<<" "<<(f(n)^s(n))<<" "<<!(f(n)||s(n));
    return 0;
}