#include<stdio.h>
struct Node{
	int l,r;
}pool[1000005];
int n,tp1,tp2,ans=1<<31;
void dfs(int n,int d=0){
	if(d>ans&&pool[n].l==0&&pool[n].r==0){
		ans=d;
		return;
	}
	if(pool[n].l)
		dfs(pool[n].l,d+1);
	if(pool[n].r)
		dfs(pool[n].r,d+1);
	return;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&pool[i].l,&pool[i].r);
	dfs(1);
	printf("%d",ans+1);
	return 0;
}