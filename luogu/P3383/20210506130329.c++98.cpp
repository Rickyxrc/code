#include<bits/stdc++.h>
#define maxn 100000005
using namespace std;
char check[maxn];
int prime[maxn],cnt,n,q,Tp;
void ola_prime(){
	for(int i=2;i<=n;i++){
//		printf("i=%d\n",i);
		if(!check[i])
			prime[++cnt]=i;
		for(int j=1;j<=cnt;j++){
//			printf("j=%d\n",j);
			if(i*prime[j]>n)break;
//			printf("c1\n");
			check[i*prime[j]]=1;
//			printf("c2\n");
			if(!(i%prime[j]))break;
//			printf("c3\n");
		}
	}
	return;
}
int main(){
// 	freopen("P3383_1.in","r",stdin);
// 	freopen("P3383.out","w",stdout);
	scanf("%d%d",&n,&q);
//	printf("n=%d,q=%d\n",n,q);
	ola_prime();
	for(int i=1;i<=q;i++){
		scanf("%d",&Tp);
		printf("%d\n",prime[Tp]);
	}
	return 0;
}