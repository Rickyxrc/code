#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	unsigned int x,i=0,s=2147483648;
	cin>>x;
	if(x%2){
		cout<<"-1";
		return 0;
	}
	bool f=1;
	while(x){
		if(x>=s){
			if(!f)
				cout<<" ";
			if(f)
				f=0;
			cout<<s;
			x-=s;
		}
		s/=2;
	}
	return 0;
}