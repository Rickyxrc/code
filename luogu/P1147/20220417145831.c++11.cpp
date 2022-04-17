#include<stdio.h>
#define maxn 2000005
int prefixs[maxn];
int n,ll,rr,m,k;
int main(){
	scanf("%d",&m);
	prefixs[1]=1;
	for(int i=1;i<=m;i++)
		prefixs[i] = i+prefixs[i-1];
//		printf("[%d]",prefixs[i]);
	
	ll=1;
	rr=2;
	while(rr<m){
		k = (prefixs[rr]-prefixs[ll-1]);
//		printf("%d %d [%d]\n",ll,rr,k);
		while(k>m)
			ll++,
			k = (prefixs[rr]-prefixs[ll-1]);
		if(k==m)
			printf("%d %d\n",ll,rr);
		rr++;
	}
	return 0;
}