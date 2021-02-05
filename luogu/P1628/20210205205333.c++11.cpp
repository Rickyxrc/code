#include<bits/stdc++.h>
using namespace std;
string r,tp_;
vector<string> m(0);
inline bool cp(string i,string j){
	return i<j;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tp_;
		m.push_back(tp_);
	}
	cin>>r;
	sort(m.begin(),m.end(),cp);
	for(vector<string>::iterator i=m.begin();i!=m.end();i++)
		if(r==(*i).substr(0,r.length()))
			cout<<*i<<endl;
	return 0;
}