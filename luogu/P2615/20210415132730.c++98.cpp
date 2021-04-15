#include<bits/stdc++.h>
using namespace std;

static char st[100];
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

int k[101][101],x,y;
int main(){
	int n;
	cin>>n;
	y=n/2+1,x=1;
	for(int i=1;i<=n*n;i++){
		k[x][y]=i;
		if(k[(x-2+n)%n+1][y%n+1]==0){
			x=(x-2+n)%n+1,y=y%n+1;
			continue;
		}
		if(x==n)
			x=1;
		else
			x++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			write(k[i][j]);putchar(' ');
		}
		putchar('\n');
	}
		
}