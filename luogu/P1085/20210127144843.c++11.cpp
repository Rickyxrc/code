#include<bits/stdc++.h>
using namespace std;
int main(){
	int k[8],tp,tpp,mx_ind=0,mx=0;
	memset(k,0,sizeof(k));
		for(int j=1;j<=7;j++){
			cin>>tp>>tpp;
			k[j]+=tp+tpp;
		}
	for(int i=1;i<=7;i++){
		if((k[i]-8)>mx){
			mx_ind=i;
			mx=k[i];
		}
	}
	cout<<mx_ind;
	return 0;
}