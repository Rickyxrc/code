#include<stdio.h>
#include<cmath>

double eps = 1e-10;

long long g=1,a,b;

double func(long long x){
//	printf("func %lf = %lf\n",x,b*(x-1)+a / sqrt(x));
	return b*double(x-1.00) + a / sqrt(x);
}

inline double min(double a,double b){
	return a<b?a:b;
}

void sfen(){
	unsigned long long l = 1,r = 1e18+7,len,mid1,mid2;
	
	len = (r-l)/3;
	mid1=l+len;
	mid2=r-len;
	
	while(mid2-mid1 > 5){
		
		len = (r-l)/3;
		mid1=l+len;
		mid2=r-len;
		
		
		if(func(mid1) <= func(mid2))
            r = mid2;
        else
            l = mid1;
	}
	
	double ans = 1e100;
	for(unsigned long long i=l;i<=r;i++){
		ans=min(ans,func(i));
	}
	printf("%.10lf\n",ans);
	
//	return mid1;
}

int main(){
	scanf("%lld %lld",&a,&b);

	sfen();
}