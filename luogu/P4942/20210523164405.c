#include<stdio.h>
typedef long long Int;
Int T,n,m,Tp,sum;
Int main(){
	scanf("%lld",&T);
	for(Int i=1;i<=T;i++){
		sum=0;
		scanf("%lld%lld",&n,&m);
		Tp=(m-n+1)%9;
		for(Int j=1;j<=Tp;j++)
			sum+=(j+n-1)%9;
		putchar((sum%9)+48);putchar('\n');
	}
	return 0;
}