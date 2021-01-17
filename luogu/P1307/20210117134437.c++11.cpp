#include<bits/stdc++.h>
using namespace std;
int main(){
	string m;
	cin>>m;
	bool g=0;
	if(m[0]=='-'){
		m.erase(0,1);
		g=1;
	}
	int i=m.length()-1;
	while(m[i]=='0'&&i>0)i--;
	if(g)
		cout<<'-';
	for(;i>=0;i--){
		cout<<m[i];
	}
	return 0;
}