#include<cstdio>
#define maxn 101
int k[maxn],n;
int main(){
	scanf("%d",&n);
	printf("%d",n);
	putchar('\n');
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i){putchar(k[j]^48);continue;}
			k[j]=!k[j];
			putchar(k[j]^48);
		}
		putchar('\n');
	}
	return 0;
} 