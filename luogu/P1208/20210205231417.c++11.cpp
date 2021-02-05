#include<bits/stdc++.h>
using namespace std;
struct milk{
	unsigned int price;
	unsigned int limit;
}man[50000];
inline bool cp(milk i,milk j){
	return (i.price<j.price);
}
int main(){
	int n,m,prc=0,tp;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>man[i].price>>man[i].limit;
	sort(man+1,man+m+1,cp);
	for(int i=1;i<=n&&n;i++){
		tp=(n>=man[i].limit)?(man[i].limit):(n);
		n-=tp;
		prc+=tp*man[i].price;
	}
	cout<<prc;	
}