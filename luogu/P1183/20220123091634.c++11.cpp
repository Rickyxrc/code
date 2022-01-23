#include<bits/stdc++.h>
using namespace std;
struct pos{int x,y;}p[111];
inline int func(const pos& a,const pos& b,const pos& c){return ((b.x-a.x)*(c.y-b.y)-(c.x-b.x)*(b.y-a.y));} 
inline int area(const pos& b,const pos& c){return (b.x*c.y)-(c.x*b.y);}
inline int read(){
	char ch;register int x=0, f=1;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
static char st[30];
inline void write(register int x){
	if(x==0){putchar('0');return;}
	if(x<0){putchar('-');x=-x;}
	register int top=0;
	while(x)st[top++]=x%10,x/=10;
	while(top)putchar(st[--top]+48);
	return;
}

int main(){
	register int n=read();
	for(register int i=1;i<=n;i++)
		p[i].x=read(),
		p[i].y=read();
	p[n+1].x=p[1].x;
	p[n+1].y=p[1].y;
	register int areas=0;
	for(register int i=1;i<=n;i++)
		areas+=area(p[i],p[i+1]);
	if(areas<0)
		areas=-areas;
	write(areas>>1);
	return 0;
}