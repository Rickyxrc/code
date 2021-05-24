#include<stdio.h>
typedef long long Int;
Int T,n,m,Tp,sum;
int main(){
	scanf("%lld",&T);
	for(Int i=1;i<=T;i++){
		sum=0;
		scanf("%lld%lld",&n,&m);
		putchar(((n+m)*5%9*(m-n+1)%9)+48);putchar('\n');
	}
	return 0;
}