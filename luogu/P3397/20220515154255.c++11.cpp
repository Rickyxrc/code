#include<stdio.h>
#define maxn 1007
int diff[maxn][maxn];
int fx,fy,tx,ty,n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&fx,&fy,&tx,&ty);
		diff[fx][fy]++;
		diff[tx+1][fy]--;
		diff[fx][ty+1]--;
		diff[tx+1][ty+1]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			diff[i][j]+=diff[i][j-1]+diff[i-1][j]-diff[i-1][j-1];
			printf("%d ",diff[i][j]);
		}
		printf("\n");
	}
		
	
	return 0;
}