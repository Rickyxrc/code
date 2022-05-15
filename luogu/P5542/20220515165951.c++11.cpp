#include<stdio.h>
#define maxn 1007
int diff[maxn][maxn];
int fx,fy,tx,ty,n,k,my,mx,s;
int maxx(int i,int j){return i>j?i:j;}
int minn(int i,int j){return i<j?i:j;}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&fx,&fy,&tx,&ty);
		fx++,fy++;
		diff[fx][fy]++;
		diff[tx+1][fy]--;
		diff[fx][ty+1]--;
		diff[tx+1][ty+1]++;
		my = maxx(my,ty+1);
		mx = maxx(mx,tx+1);
	}
	for(int i=1;i<=mx;i++){
		for(int j=1;j<=my;j++){
			diff[i][j]+=diff[i][j-1]+diff[i-1][j]-diff[i-1][j-1];
			if(diff[i][j] == k)
				s++;
		}
	}
	printf("%d",s);
	
	return 0;
}