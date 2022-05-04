#include<stdio.h>
#define maxn 100003
int ls[maxn],n,k,b,t,mx=114514,cnt;
int main(){
	scanf("%d%d%d",&n,&k,&b);
	for(int i=1;i<=b;i++)
		scanf("%d",&t),
		ls[t]=1;
	for(int i=1;i<=n-k;i++){
		cnt=0;
		for(int j=1;j<=k;j++)
//			printf("%d ",ls[i+j]),
			cnt+=ls[i+j];
		mx=cnt<mx?cnt:mx;
//		printf("\n");
	}
	printf("%d",mx);
	return 0;
}
