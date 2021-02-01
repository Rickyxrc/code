#include<bits/stdc++.h>
using namespace std;
int x,y,k;
void exgcd(int a,int b)
{
    if(!b){
		x=1;
		y=0;
		return;
	}
    exgcd(b,a%b);
    k=x;
	x=y;
    y=k-a/b*y;
    return;
}
int main()
{
	ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    exgcd(n,m);
    cout<<(x+m)%m;
}
/*
ax+by=gcd(a,b)
*/