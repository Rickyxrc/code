#include<bits/stdc++.h>
using namespace std;
int main(){
	long double k;
	long double sum=0;
	while(cin>>k)
		sum+=(long long)(k*1000000);
	cout<<fixed<<setprecision(5)<<(long double)sum/1000000.0;
	return 0;
}