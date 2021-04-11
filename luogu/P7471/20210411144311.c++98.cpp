#include<cstdio>
#include<algorithm>
#include<bits/locale_facets.h>
#define putnum(A) putchar(A+48)
using namespace std;
inline int read(){
	char ch;
	int f=0,x=1;
	while(!isdigit(ch)){ch=getchar();}
	while( isdigit(ch))f=(f<<3)+(f<<1)+(ch^48),ch=getchar();
	return f;
}
int main(){
	int k[4],T;
	T=read();
	for(int i=1;i<=T;i++){
		k[1]=read();
		k[2]=read();
		k[3]=read();
		sort(k+1,k+4);
		if(k[1]==0&&k[2]==0)
			putnum(0);
		else if(k[1]==0)
			putnum(2-(k[2]==k[3]));
		else if(k[1]==k[2]||k[2]==k[3])
			putnum(2);
		else if(k[1]!=k[2])
			if(k[1]+k[2]==k[3])
				putnum(2);
			else if(k[2]==k[3])
				putnum(2);
			else
				putnum(3);
		putchar('\n');
	}
	return 0;
} 