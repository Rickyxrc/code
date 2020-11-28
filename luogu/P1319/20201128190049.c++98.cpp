#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int num=0,m;
	bool flag=0;
	while(num!=n*n){
		cin>>m;
		for(int i=1;i<=m;i++){
			cout<<flag;
			num++;
			if(num%n==0)
				cout<<endl;
		}
		flag=!flag;
	} 
	return 0;
} 