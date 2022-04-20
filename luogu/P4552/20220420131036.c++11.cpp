#include<stdio.h>
#define maxn 100007
long long t,n,ttp,zheng,fu,list[maxn];
long long max(long long ii,long long jj){return ii>jj?ii:jj;}
long long abs(long long ii){return ii<0?-ii:ii;}
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&list[i]);
	}
	for(int i=2;i<=n;i++){
		ttp = list[i]-list[i-1];
		if(ttp>0)
			zheng+=ttp;
		else
			fu-=ttp;
	}
	printf("%lld\n%lld",max(zheng,fu),abs(zheng-fu)+1);
	return 0;
}