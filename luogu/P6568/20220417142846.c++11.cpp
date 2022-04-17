#include<stdio.h>
#define maxn 1000007
int a[maxn],n,k,rl,rr,maxx=-1,now;
int maxxx(int ii,int jj){
	return ii>jj?ii:jj;
}
int main(){
	scanf("%d%d",&n,&k);
	rl = 1;
	for(int ri=1;ri<=n;ri++)
		scanf("%d",&a[ri]);
		
	rl=1;
	rr=k+1;
	for(int i=1;i<=rr;i++)
		now += a[i];
	
	while(rr<=n){
		maxx = maxxx(maxx,now);
		now -= a[rl];
		rl++,rr++;
		now += a[rr];
	}
	
	printf("%d",maxx);
	return 0;
}