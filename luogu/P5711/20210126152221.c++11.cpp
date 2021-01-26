#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int y;
    cin>>y;
    if(y%400==0)
        cout<<1;
    else if(y%100!=0&&y%4==0)
        cout<<1;
    else
        cout<<0;
}