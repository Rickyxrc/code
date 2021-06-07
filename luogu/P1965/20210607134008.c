#include<stdio.h> 
typedef unsigned long long Int;
Int n;
Int qpow(Int a,Int b){
    Int ans=1,base=a;
    while(b){
		if(b&1)
	    	ans=(ans*base)%n;
	    base=(base*base)%n;
	    b>>=1;
    }
    return ans;
}
int main(){
	Int m,k,x;
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	printf("%lld",(x%n+m%n*qpow(10,k))%n)%n;
	return 0;
}