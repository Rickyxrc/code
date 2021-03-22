#include<bits/stdc++.h>
#define maxn 401

#define nx q.front().first
#define ny q.front().second

using namespace std;

bool f[maxn][maxn];
int  k[maxn][maxn];

struct pairr{
	int first;
	int second;
	int n;
};
queue<pairr>q;
pair<int,int>d[9];

int main(){
	
	d[1]=make_pair(1, 2);
	d[2]=make_pair(1,-2);
	d[3]=make_pair(-1,2);
	d[4]=make_pair(-1,-2);
	d[5]=make_pair(-2,1);
	d[6]=make_pair(2,-1);
	d[7]=make_pair(-2,-1);
	d[8]=make_pair(2,1);
	
	int n,m,startx,starty;
	scanf("%d%d%d%d",&n,&m,&startx,&starty);
	q.push({startx,starty,0});
	while(q.size()){
//		printf("%d %d %d \n",nx,ny,q.front().n);
		f[nx][ny]=1;
		k[nx][ny]=q.front().n;
		for(int i=1;i<=8;i++){
			if(f[nx+d[i].first][ny+d[i].second]==0&&nx+d[i].first<=n&&ny+d[i].second<=m&&nx+d[i].first>=1&&ny+d[i].second>=1)
				q.push({nx+d[i].first,ny+d[i].second,q.front().n+1}),
				f[nx+d[i].first][ny+d[i].second]=1;
		}
		q.pop();
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(i==startx&&j==starty)
				printf("%-5d",0);
			else if(k[i][j]==0)
				printf("%-5d",-1);
			else
				printf("%-5d",k[i][j]);
		putchar('\n');
	}
	
	return 0;
}