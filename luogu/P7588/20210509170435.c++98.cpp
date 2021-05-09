#include<bits/stdc++.h>
#define maxn 100000005
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

int prime[maxn],cnt,n,T,mxn,Tp,Tp_,ans;
char check[maxn];
void ola_prime(){
	check[1]=1;
	for(int i=2;i<=maxn;i++){
		if(!check[i])
			prime[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(i*prime[j]>maxn)break;
			check[i*prime[j]]=1;
			if(!(i%prime[j]))break;
		}
	}
	return;
}
inline int summ(const int& x){
	if(!x)
		return 0;
	int k=x,s=0;
	while(k)
		s+=k%10,k/=10;
	return s;
}

int main(){
	T=read();
	ola_prime();
	for(int i=1;i<=T;i++){
		ans=0;
		Tp= read();
		Tp_=read();
		for(int i=Tp;i<=Tp_;i++){
			if((!check[i])&&(!check[summ(i)]))
				ans++;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}