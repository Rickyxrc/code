#include<stdio.h>
#include<bitset>
char check[100000005];
int prime[10000000];
int n,cnt;
void ola_prime(){
	register int k;
	check[1]=1;
	for(int i=2;i<=n;i++){
		if(!check[i])
			prime[++cnt]=i;
		for(int j=1;prime[j]*i<=n&&j<=cnt;j++){
			check[i*prime[j]]=1;
			if(!(i%prime[j]))break;
		}
	}
	return;
} 
int main(){	
	scanf("%d",&n);
	ola_prime();
	printf("%d",cnt);
	return 0;
} 