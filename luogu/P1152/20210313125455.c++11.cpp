#include<bits/stdc++.h>
using namespace std;
bool a[100001];
int n;
bool jolly(){
//	cout<<"check"<<endl;
	for(int i=1;i<=n-1;i++)
		if(a[i]==0){
//			cout<<i<<endl;
			return 0;
		}
	return 1;
}
int main()
{
	int Tp,Tpp;
	cin>>n;
	if(n==1){
		cout<<"Jolly";
	}
	cin>>Tp;
	for(int i=1;i<=n-1;i++){
		cin>>Tpp;
		a[abs(Tp-Tpp)]=1;
//		cout<<abs(Tp-Tpp)<<endl;
		Tp=Tpp;
	}
	if(jolly())
		cout<<"Jolly";
	else
		cout<<"Not jolly";
	return 0;
}