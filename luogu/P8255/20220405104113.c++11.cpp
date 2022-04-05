#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
#include<iostream>
long long gcd(long long a,long long b)
{
    long long r;
	while (a%b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return b; 
}
int main(){
	int n;
	long long x,z,d;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x,&z);
		if(z%x==0){
			long long gcc = gcd(x*x,z/x);
			long long d = std::sqrt(gcc);
			if(d*d==gcc)
				printf("%lld\n",(z/x)/d);
			else
				printf("-1\n");
		}
		else
			printf("-1\n");
			
	}
}