#include<bits/stdc++.h>
using namespace std;
unsigned short a,b,c,d;
int main(){
	unsigned short k;
	bool flag=0;
	cin>>k;
	for(int i=10000;i<=30000;i++){
		a=i/100;
		b=(i-(i/10000)*10000)/10;
		c=i-(i/1000)*1000;
		if(a%k==0&&b%k==0&&c%k==0){
			if(flag)
				cout<<endl;
			cout<<i;
			flag=1;
		}		
	}
	if(flag==0)
		cout<<"No";
} 