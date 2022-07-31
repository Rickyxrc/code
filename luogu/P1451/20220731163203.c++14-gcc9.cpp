#include<stdio.h>
#define maxn 5007
char map_[maxn][maxn],tch;
int n,m,ans;
char getChar(){
	while(tch=getchar())
		if(tch != '\n' && tch != '\r' && tch != ' ')
			return tch;
}
void floyd_fill(int x,int y){
	if(x<1||x>n||y<1||y>m)
		return;
	if(map_[x][y]!='0'){
		map_[x][y]='0';
		floyd_fill(x+1,y);
		floyd_fill(x,y-1);
		floyd_fill(x-1,y);
		floyd_fill(x,y+1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			map_[i][j] = getChar();
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(map_[i][j]!='0')
				floyd_fill(i,j),ans++;
	
	printf("%d",ans);
}