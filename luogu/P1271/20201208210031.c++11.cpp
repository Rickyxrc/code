#include<bits/stdc++.h>
int a[2000000+2];
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	sort(a+1,a+m+1);
	for(int i=1;i<=m-1;i++)
		cout<<a[i]<<" ";
	cout<<a[m];
	return 0;
}