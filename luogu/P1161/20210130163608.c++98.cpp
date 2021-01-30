#include<bits/stdc++.h>
using namespace std;
bool k[2000001];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	double a;
	int t;
	for(int i=1;i<=n;i++){
		cin>>a>>t;
			for(int j=1;j<=t;j++){
				k[int(j*a)]=!k[int(j*a)];
			}
	}
	int i=1;
	for(i=1;;i++){
		if(k[i]){
			cout<<i;
			return 0;
		}
	}
	return 0;
}