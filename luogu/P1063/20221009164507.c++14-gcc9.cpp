#include<stdio.h>
#include<memory.h>
#define maxn 1007
int n
	,stones[maxn*2]
	,dpmx[maxn][maxn],ans;
int maxx(int a,int b){
	return a>b?a:b;
}
int main(){
	memset(dpmx,0x00,sizeof(dpmx));
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&stones[i]),
		stones[i+n] = stones[i];
	
	for(int j=2;j<=(n<<1);j++)
		for(int i=j-1;i>0&&j-i<n;i--)
			for(int k=i;k<j;k++) 
		 		dpmx[i][j] = maxx(
		 			dpmx[i][j],
		 			dpmx[i][k] + dpmx[k+1][j] + stones[i] * stones[k+1] * stones[j+1]
				 ),
				ans = maxx(ans,dpmx[i][j]);
	printf("%d\n",ans);
	return 0;
}
