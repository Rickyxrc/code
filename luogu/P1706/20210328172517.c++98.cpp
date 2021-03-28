#include<bits/stdc++.h>
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

int book[10],n,stt[10];
void dfs(int step){
	if(n+1==step){
		for(int i=1;i<=n;i++)
			putchar(' '),
			putchar(' '),
			putchar(' '),
			putchar(' '),
			putchar(stt[i]+48); 
		putchar('\n');
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			book[i]=1;
			stt[step]=i;
			dfs(step+1);
			book[i]=0;
		}
	}
	return;
}
int main(){
	n=read();
	
	dfs(1);
	return 0;
}