#include<stdio.h>
int main(){
	long long a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	printf("%s",(long long)(a*a)>(long long)(b*c)?"Alice":"Bob");
	return 0;
} 