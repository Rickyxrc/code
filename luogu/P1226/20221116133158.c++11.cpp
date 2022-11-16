#include<stdio.h>
#define int long long
int pow(int a,int p,int mod){
	int ans = 1,base = a;
    while(p){
        if(p&1)
            ans=ans*base%mod;
        p>>=1;
        base=base*base%mod;
    }
    return ans%mod;
}
signed main(){
	int a,b,mod;
	scanf("%lld%lld%lld",&a,&b,&mod);
	printf("%lld^%lld mod %lld=%lld",a,b,mod,pow(a,b,mod));
	return 0;
}