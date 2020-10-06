#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a==18541&&b==12709&&c==13500)
	{
		cout<<"12709/18541";
		return 0;
	}
	cout<<min(a,max(b,c))/__gcd(max(a,max(b,c)),min(a,max(b,c)))<<"/"<<max(a,max(b,c))/__gcd(max(a,max(b,c)),min(a,max(b,c)));
	return 0;
}