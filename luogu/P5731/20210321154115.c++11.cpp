#include<bits/stdc++.h>
//#include<conio.h>
using namespace std;
int k[50][50];
int main(){
	int n;
	cin>>n;
	if(n==1){
		cout<<"  1";
		return 0;
	}
	int cnt=0,x=1,y=1,mx=n*n;
	char fwd='r';
	while(cnt-mx){
		k[x][y]=++cnt;
		flg:
		if(cnt-mx==-1)
			break;
		switch(fwd){
			case 'u':
				if(y==n||k[x][y+1]){
					fwd='r';
					goto flg;
					break;
				}
				y++;
				break;
			case 'd':
				if(y==1||k[x][y-1]){
					fwd='l';
					goto flg;
					break;
				}
				y--;
				break;
			case 'l':
				if(x==1||k[x-1][y]){
					fwd='u';
					goto flg;
					break;
				}
				x--;
				break;
			case 'r':
				if(x==n||k[x+1][y]){
					fwd='d';
					goto flg;
					break;
				}
				x++;
				break;
			default:
				abort();
		}
//		system("cls");
//			cout<<x<<" "<<y<<" "<<cnt<<" "<<mx<<endl;
//			for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<setw(3)<<k[j][i];
//			}
//			cout<<endl;
//			}
//		getch();
//		system("pause");
	}
	if(n%2)
		k[x+1][y]=++cnt;
	else
		k[x-1][y]=++cnt;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<setw(3)<<k[j][i];
		}
		cout<<endl;
	}
}