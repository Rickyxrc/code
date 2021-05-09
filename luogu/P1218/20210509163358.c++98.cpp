#include<bits/stdc++.h>
int maxn=100000005;

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

int n,Tp,cnt;
inline bool prime(const int& n)
{
	if(n<2)
		return false;
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}
void build(int i,int now=1){
//	printf("build %d\n",i);
	if(now==n){
		write(i),
		putchar('\n');
		return;
	}	
	for(int j=0;j<=9;j++){
		if(prime(i*10+j))build(i*10+j,now+1);
	}
}

bool canb;
int main(){
	n=read();
	build(2);build(3);build(5);build(7);
	return 0;
}