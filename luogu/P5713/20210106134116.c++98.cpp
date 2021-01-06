#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cin>>num;
    int lg=num*3+11;
    int ud=num*5;
    if(lg<ud)
        cout<<"Luogu";
    else
        cout<<"Local";
    return 0;
}