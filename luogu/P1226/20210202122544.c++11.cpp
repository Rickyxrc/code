#include<bits/stdc++.h>
using namespace std;
long long qpow(long long a,long long n,long long mod)
{
    long long ans=1;
    while(n)
    {
        if(n&1)
            ans=(ans*a)%mod;
        n>>=1;
        a=(a*a)%mod;
    }
    return ans%mod;
}
int main(){
	int b,p,k,s;
	cin>>b>>p>>k;
	s=qpow(b,p,k)%k;
	cout<<b<<"^"<<p<<" mod "<<k<<"="<<s;
	return 0;
}