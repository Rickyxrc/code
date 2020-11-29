#include<bits/stdc++.h>
using namespace std;
struct s{
	int _time_;
	int num;
}t[1005];
bool bj(s a,s b){
	return a._time_<b._time_;
}
int main(){
//	int t[1005];
	int n;
	cin>>n;
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>t[i]._time_;
		t[i].num=i+1;
	}
	sort(t,t+n,bj);
//	cout<<t;
	for(int i=0;i<n-1;i++){
		cout<<t[i].num<<" ";
		for(int j=0;j<i+1;j++){
			ans=ans+t[j]._time_;
		}
	}
	cout<<t[n-1].num<<endl;
//	cout<<ans<<endl;
	cout<<fixed<<setprecision(2)<<(double)ans/(double)n;
}

