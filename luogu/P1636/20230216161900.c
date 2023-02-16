#include<stdio.h>

#define maxn 1007

int deg[maxn];

int n,m,u,v,res;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u,&v),
		deg[v]^=1,deg[u]^=1;
	for(int i=1;i<=n;i++)
		res+=deg[i];
	if(res == 0)
		return putchar('1')&0;
	printf("%d",res/2);
	return 0;
} 