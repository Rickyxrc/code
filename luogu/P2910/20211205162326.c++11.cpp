#include<stdio.h>
#include<memory.h>

#define maxn 105
int mp[maxn][maxn],n,m,a,b,c,q[10005],s;

int min(int a,int b){return a<b?a:b;} 

int main(){
	scanf("%d%d",&n,&m);
	
	memset(mp,0x3f,sizeof(mp));

	for(int i=1;i<=m;i++)
		scanf("%d",&q[i]);

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&mp[i][j]);
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(mp[i][j] > mp[i][k] + mp[k][j])
					mp[i][j] = mp[i][k] + mp[k][j];
		
	
	for(int i=2;i<=m;i++)
		s+= mp[q[i-1]][q[i]];	
	
	
	printf("%d",s);
	
	return 0;
}