#include<iostream>
#include<map>
using namespace std;

map<string,bool> mp;
int n,cnt;
string s;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(mp.find(s) == mp.end())
			mp[s] = 1,
			cnt++;
	}
	cout<<cnt;
}