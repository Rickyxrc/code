#include<bits/stdc++.h>
using namespace std;
int main(){
	string r;
	cin>>r;
	bool flag=0;
	if(r[0]=='-'){
		r.erase(0,1);
		flag=1;
	}
	if(flag)
		cout<<"-";
	flag=1;
	for(int i=r.length()-1;i>=0;i--){
		if(r[i]=='0'&&flag)
			continue;
		else
			flag=0;
		cout<<r[i];
	}
	return 0;
}