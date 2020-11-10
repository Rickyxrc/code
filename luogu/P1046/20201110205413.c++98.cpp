#include<iostream>
using namespace std;
int main(){
	short a[11];
	int m;
	for(int i=1;i<=10;i++){
		cin>>a[i];
	}
	cin>>m;
	int i=0;
	for(int j=1;j<=10;j++)
		if(m+30>=a[j])
			i++;
	cout<<i;
}
