#include<bits/stdc++.h>
using namespace std;
int main(){
	char m[105][105];
	bool k[105][105];
	memset(k,0,sizeof(k));
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
//		for(int j=1;j<=n;j++)
//			m[i][j]=getchar();
		cin>>m[i];
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++)
//			cout<<m[i][j];
//		cout<<endl;
//	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(m[i][j]=='y'&&m[i][j+1]=='i'&m[i][j+2]=='z'&&m[i][j+3]=='h'&&m[i][j+4]=='o'&&m[i][j+5]=='n'&&m[i][j+6]=='g'){
				k[i][j]=1;
				k[i][j+1]=1;
				k[i][j+2]=1;
				k[i][j+3]=1;
				k[i][j+4]=1;
				k[i][j+5]=1;
				k[i][j+6]=1;
			}
			if(m[i][j]=='y'&&m[i+1][j]=='i'&m[i+2][j]=='z'&&m[i+3][j]=='h'&&m[i+4][j]=='o'&&m[i+5][j]=='n'&&m[i+6][j]=='g'){
				k[i][j]=1;
				k[i+1][j]=1;
				k[i+2][j]=1;
				k[i+3][j]=1;
				k[i+4][j]=1;
				k[i+5][j]=1;
				k[i+6][j]=1;
			}
			if(m[i][j]=='y'&&m[i+1][j+1]=='i'&m[i+2][j+2]=='z'&&m[i+3][j+3]=='h'&&m[i+4][j+4]=='o'&&m[i+5][j+5]=='n'&&m[i+6][j+6]=='g'){
				k[i][j]=1;
				k[i+1][j+1]=1;
				k[i+2][j+2]=1;
				k[i+3][j+3]=1;
				k[i+4][j+4]=1;
				k[i+5][j+5]=1;
				k[i+6][j+6]=1;
			}
			if(m[i][j]=='y'&&m[i][j-1]=='i'&m[i][j-2]=='z'&&m[i][j-3]=='h'&&m[i][j-4]=='o'&&m[i][j-5]=='n'&&m[i][j-6]=='g'){
				k[i][j]=1;
				k[i][j-1]=1;
				k[i][j-2]=1;
				k[i][j-3]=1;
				k[i][j-4]=1;
				k[i][j-5]=1;
				k[i][j-6]=1;
			}
			if(m[i][j]=='y'&&m[i-1][j]=='i'&m[i-2][j]=='z'&&m[i-3][j]=='h'&&m[i-4][j]=='o'&&m[i-5][j]=='n'&&m[i-6][j]=='g'){
				k[i][j]=1;
				k[i-1][j]=1;
				k[i-2][j]=1;
				k[i-3][j]=1;
				k[i-4][j]=1;
				k[i-5][j]=1;
				k[i-6][j]=1;
			}
			if(m[i][j]=='y'&&m[i-1][j-1]=='i'&m[i-2][j-2]=='z'&&m[i-3][j-3]=='h'&&m[i-4][j-4]=='o'&&m[i-5][j-5]=='n'&&m[i-6][j-6]=='g'){
				k[i][j]=1;
				k[i-1][j-1]=1;
				k[i-2][j-2]=1;
				k[i-3][j-3]=1;
				k[i-4][j-4]=1;
				k[i-5][j-5]=1;
				k[i-6][j-6]=1;
			}
		}	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(k[i][j]==1)
				cout<<m[i][j];
			else
				cout<<"*";
		cout<<endl;
	}
		
	return 0;
}