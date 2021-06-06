#include<stdio.h> 
typedef unsigned long long Int;
Int qpow(Int a,Int b,Int mod){
    Int ans=1,base=a;
    while(b!=0){
		if(b&1)
	    	ans=ans*base%mod;
	    b>>=1;	
		base=base*base%mod;
    }
    return ans%mod;
}
int main(){
	Int a,b,m;
	scanf("%lld%lld%lld",&a,&b,&m);
	printf("%lld^%lld mod %lld=%lld",a,b,m,qpow(a,b,m)%m);
	return 0;
}