#include<bits/stdc++.h>
using namespace std;
int main(){
	int cf=0,zf=0;
	int a,b;
	cin>>a>>b;
	a++;
	b++;
	for(int i=1;i<=a;i++)	
		for(int j=1;j<=b;j++)
			for(int ii=i+1;ii<=a;ii++)
				for(int jj=j+1;jj<=b;jj++)
//					cout<<i<<" "<<j<<"|"<<ii<<" "<<jj<<endl;
					if((ii-i)==(jj-j))
						zf++;
					else cf++;
	cout<<zf<<" "<<cf;
	return 0;
}