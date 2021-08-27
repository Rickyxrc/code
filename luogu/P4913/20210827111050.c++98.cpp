#include<stdio.h>
struct{
	int l;
	int r;
}tree[1000001];
int n,Tp,Tp_,ans=1<<31;
void dfs(int step,int tmp){ 
	if(tree[step].l == 0 && tree[step].r == 0){
		ans=ans>tmp?ans:tmp;
		return;
	}
	dfs(tree[step].l,tmp+1);
	dfs(tree[step].r,tmp+1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&tree[i].l,&tree[i].r);
	}
	dfs(1,0);
	printf("%d",ans+1);
}