#include<stdio.h>
#define maxn 1007
int ti,tj,tt,ans;
int rn[maxn];
int main(){
	scanf("%d%d",&ti,&tj);
	for(int i=1;i<=tj;i++)
		for(int j=1;j<=ti;j++)
			scanf("%d",&tt),rn[j]+=tt;
	for(int i=1;i<=ti;i++)
		scanf("%d",&tt),ans+=((rn[i]>(tj-rn[i]))==tt);
	printf("%d",ans);	
	return 0;
}