#include<bits/stdc++.h>
//#include<conio.h>
using namespace std;
char k[110][110];
int m,n;
bool f[110][110];
void dfs(int i,int j){
	if(k[i][j]=='0')
		return;
	if(i>n||i<1||j>m||j<1)
		return;
	if(f[i][j])
		return;
	
	f[i][j]=1;
	k[i][j]='0';  
	
//	system("cls");
//	cout<<i<<" "<<j<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)
//			putchar(k[i][j]);
//		putchar('\n');
//	}
//	getch();
	
	dfs(i+1,j);
	dfs(i-1,j);
	dfs(i,j+1);
	dfs(i,j-1);
	return;
}
int main(){
	int cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>k[i][j];
			
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)
//			putchar(k[i][j]);
//		putchar('\n');
//	}
//	putchar('\n');
			
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(k[i][j]>'0'){
//				cout<<i<<" "<<j<<endl;
				dfs(i,j),
				cnt++;
//				for(int i=1;i<=n;i++){
//					for(int j=1;j<=m;j++)
//						putchar(k[i][j]);
//					putchar('\n');
//				}
//				putchar('\n');
			}
				
	cout<<cnt;
	return 0;
}