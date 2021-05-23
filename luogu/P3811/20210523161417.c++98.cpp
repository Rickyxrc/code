#include<stdio.h>
#include<bits/locale_facets.h>
using namespace std;
typedef long long Int;

Int x,y,n,m,Tp,Tp_,inv[3000010];

inline Int read(){
	char ch;
	int f=0;
	Int x=1;
	while(!isdigit(ch)){ch=getchar();}
	while( isdigit(ch))f=(f<<3)+(f<<1)+(ch^48),ch=getchar();
	return f;
}
static char st[30];
inline void write(Int x){
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

int main(){
    Tp=read();
    Tp_=read();
    inv[1]=1;
    putchar(49);putchar('\n');
    for(Int i=2;i<=Tp;i++){
    	inv[i]=(Tp_-Tp_/i)*inv[Tp_%i]%Tp_;
    	write(inv[i]);
    	putchar('\n');
    }
}
/*
ax+by=gcd(a,b)
*/