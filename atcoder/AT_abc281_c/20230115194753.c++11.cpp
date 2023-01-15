#include<stdio.h>

#define int long long

const int maxn = 1e5+7;

int time[maxn],n,t,sum;

signed main(){
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=n;i++)
		scanf("%lld",time+i),
		sum += time[i];
	
	t %= sum;
	
	for(int i=1;i<=n;i++){
		if(t<time[i])
			return 0&printf("%lld %lld",i,t);
		t -= time[i];
	}
	return 0;
}