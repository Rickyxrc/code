#include<bits/stdc++.h>
using namespace std;
int main(){
	double lf=10,exp=0;
	double lff,expp;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>lff>>expp;
        //cout<<i+1<<" "<<lf<<" "<<exp<<endl;
		lf=lf-lff;
		if(lf<=0)
			break;
		if(lf>10)
			lf=10;
		exp+=expp;
	}
	int r=1,lv=0;
	while(1){
		if(exp<r)
			break;
		else if(exp>=r){
		exp=exp-r;
		r*=2;
		lv++;
        }
        //cout<<(int)lv<<" "<<(int)exp<<endl;
	}
	cout<<(int)lv<<" "<<(int)exp;
	return 0;
}