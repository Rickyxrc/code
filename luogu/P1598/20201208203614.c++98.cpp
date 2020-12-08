#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("123.txt","r",stdin);
	string a;
	int count[27];
	int maxx=-1;
	memset(count,0,sizeof(count));
	for(int i=1;i<=4;i++){
		getline(cin,a);
		for(int j=0;j<a.length();j++){
			count[a[j]-'A'+1]++;
			if(a[j]>='A'&&a[j]<='Z')
			maxx=max(maxx,count[a[j]-'A'+1]);
//			cout<<maxx<<" ";
		}
	}
//	cout<<endl;
//	for(int i=1;i<=26;i++){
//		cout<<count[i]<<" ";
//	}
//	cout<<endl<<maxx; 
	for(int i=maxx;i>=1;i--){
		for(int j=1;j<=25;j++){
			if(count[j]>=i)
				cout<<"*";
			else
				cout<<" ";
			cout<<" ";
//			cout<<j;
		}
		if(count[26]>=i)
				cout<<"*";
			else
				cout<<" ";
//		cout<<i<<endl;
		cout<<endl;
	}
//	cout<<endl;
	for(int i=1;i<=25;i++){
		cout<<(char)(i+'A'-1)<<" ";
	}
	cout<<'Z';
	return 0;
}