#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define next i,j+1
int T,n,m,ans=0,maxx=0;
int map[8][8],cnt[8][8];
int max(int a,int b){
	return a>b?a:b;
}
void dfs(int i,int j){
	if(j>m){
		dfs(i+1,1);
		return;
	}
	if(i>n){
		maxx=max(ans,maxx);
		return;
	}
	dfs(next);
	if(cnt[i][j]==0){
		ans+=map[i][j];
		cnt[i-1][j-1]++;
		cnt[i-1][j]++;
		cnt[i-1][j+1]++;
		cnt[i][j-1]++;
		cnt[i][j]++;
		cnt[i][j+1]++;
		cnt[i+1][j-1]++;
		cnt[i+1][j]++;
		cnt[i+1][j+1]++;
		
		dfs(next);
		
		cnt[i-1][j-1]--;
		cnt[i-1][j]--;
		cnt[i-1][j+1]--;
		cnt[i][j-1]--;
		cnt[i][j]--;
		cnt[i][j+1]--;
		cnt[i+1][j-1]--;
		cnt[i+1][j]--;
		cnt[i+1][j+1]--;
		ans-=map[i][j];
	}
	return;
}
int main(){
	
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d%d",&n,&m);
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				scanf("%d",&map[j][k]);
		maxx=0,ans=0;
		dfs(1,1);
		printf("%d\n",maxx);
	} 
	return 0;
}