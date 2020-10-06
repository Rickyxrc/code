#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<min(a,min(b,c))/__gcd(max(a,max(b,c)),min(a,max(b,c)))<<"/"<<max(a,max(b,c))/__gcd(max(a,max(b,c)),min(a,max(b,c)));
	return 0;
}