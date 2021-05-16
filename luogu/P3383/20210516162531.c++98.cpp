#include<bits/stdc++.h>
#define maxn 100000005
using namespace std;
char check[maxn];
int prime[maxn],cnt,n,q,Tp;
void ola_prime(){
	for(int i=2;i<=n;i++){
		if(!check[i])
			prime[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(i*prime[j]>n)break;
			check[i*prime[j]]=1;
			if(!(i%prime[j]))break;
		}
	}
	return;
}
int main(){
	scanf("%d%d",&n,&q);
	ola_prime();
	for(int i=1;i<=q;i++){
		scanf("%d",&Tp);
		printf("%d\n",prime[Tp]);
	}
	return 0;
}