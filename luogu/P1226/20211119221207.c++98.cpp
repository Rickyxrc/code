#include<stdio.h>
typedef unsigned long long ull;
ull qpow(ull a,ull b,ull mod){
	ull res=1,base=a;
	while(b){
		if(b&1)
			res=res*base%mod;
		base=base*base%mod;
		b>>=1;
	}
	return res;
}
int main(){
	ull a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	printf("%lld^%lld mod %lld=%lld",a,b,c,qpow(a,b,c)%c);
}