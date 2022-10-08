#include<stdio.h>
#include<memory.h>
#define maxn 1007
int n,stones[maxn*2],dpmn[maxn][maxn],dpmx[maxn][maxn];
int maxx(int a,int b){
	return a>b?a:b;
}
int minn(int a,int b){
	return a<b?a:b;
}
int main(){
	memset(dpmn,0x3f,sizeof(dpmn));
	memset(dpmx,0x00,sizeof(dpmx));
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&stones[i]),
		stones[i+n] = stones[i];
	n<<=1;
	 
	for(int i=1;i<=n;i++)
		stones[i] += stones[i-1],
		dpmn[i][i]=0,
		dpmx[i][i]=0;
		
	for(int i=n;i>=1;i--)
		 for(int j=i+1;j<n;j++)
		 	for(int k=i;k<j;k++)
		 		dpmn[i][j] = minn(dpmn[i][j],dpmn[i][k]+dpmn[k+1][j]+(stones[j]-stones[i-1])),
		 		dpmx[i][j] = maxx(dpmx[i][j],dpmx[i][k]+dpmx[k+1][j]+(stones[j]-stones[i-1]));
	
	int ans = 2147483647;
	for(int i=1;i<=n;i++)
		ans = minn(ans,dpmn[i][i+(n>>1)-1]);
	printf("%d\n",ans);
	ans = 0;
	for(int i=1;i<=n;i++)
		ans = maxx(ans,dpmx[i][i+(n>>1)-1]);
	printf("%d\n",ans);
	return 0;
}
