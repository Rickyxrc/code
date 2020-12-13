#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,s,t;
	cin>>m>>s>>t;
	int run=0,mgk=0;
	for(int i=0;i<t;i++){
		run+=17;
		if(m>=10){
			mgk+=60;
			m-=10;
		}
		else if(m<10){
			m+=4;
		}
		if(mgk>run)
			run=mgk;
		if(mgk>=s||run>=s){
			cout<<"Yes"<<endl<<i+1;
			return 0;
		}
	}
	cout<<"No"<<endl<<max(mgk,run);
	return 0;
}