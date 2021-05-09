#include<bits/stdc++.h>

#define maxn 100005

using namespace std;

inline int read(){
	char ch;
	int f=0,x=1;
	while(!isdigit(ch)){ch=getchar();}
	while( isdigit(ch))f=(f<<3)+(f<<1)+(ch^48),ch=getchar();
	return f;
}
static char st[30];
inline void write(int x){
	if(x==0){
		putchar('0');
		return;
	}
	register int top=0;
	while(x)
		st[top++]=x%10,
		x/=10;
	while(top)
		putchar(st[--top]+48);
	return;
}

int prime[maxn],n,Tp,cnt;
char check[maxn];
inline void ola_prime(){
	check[1]=1;
	for(int i=2;i<=maxn;i++){
//		printf("%d\n",i);
		if(!check[i])
			prime[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(prime[j]*i>maxn)
				break;
//			printf("kick out%3d*%3d=%3d\n",prime[j],i,prime[j]*i);
			check[prime[j]*i]=1;
			if(!i%prime[j])
				break;
		}
	}
	return;
}

int main(){
	n=read();
	ola_prime(); 
//	for(int i=1;i<=20;i++){
//		printf("%d ",prime[i]);
//	}
	for(int i=1;i<=n;i++){
		Tp=read();
		if(!check[Tp]){
			write(Tp),
			putchar(' ');
		}
	}
	return 0;
}