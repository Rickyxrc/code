#include<stdio.h>
#define maxn 1007
int dp[maxn][maxn],aa[maxn],cntaa,bb[maxn],cntbb;
int n,x,y,z,t;

inline int min(int a,int b){
	return a<b?a:b;
}

inline int abs(int x){
	return x<0?-x:x;
}

int main(){
	scanf("%d%d%d%d",&n,&x,&y,&z);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		for(int j=1;j<=t;j++)
			aa[cntaa++]=i;
		scanf("%d",&t);
		for(int j=1;j<=t;j++)
			bb[cntbb++]=i;
	}
	
	for(int i=1;i<=cntbb;i++)
		dp[0][i] = i*x;
	for(int i=1;i<=cntaa;i++)
		dp[i][0] = i*y;
	
	for(int i=1;i<=cntaa;i++)
		for(int j=1;j<=cntbb;j++)
			dp[i][j] = min(min(min(i*y+j*x,dp[i-1][j]+y),dp[i][j-1]+x),dp[i-1][j-1]+z*abs(aa[i]-bb[j]));
	
	printf("%d",dp[cntaa][cntbb]);
}