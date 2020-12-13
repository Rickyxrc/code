#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("P1320_1.txt","r",stdin);
	string s;
	string m;
	cin>>m;
	s+=m;
	for(int i=1;i<=m.length()-1;i++){
		cin>>m;
		s+=m;
	}
	cout<<sqrt(s.length());
	bool flag=0;
	for(int i=0;i<s.length();){
		int cnt=0;
		while(s[i]-'0'==flag)cnt++,i++;
		flag=!flag;
		cout<<" "<<cnt;
	}
	return 0;
}