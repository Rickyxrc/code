#include<bits/stdc++.h>
using namespace std;
bool prime(int n){
	if(n==2)
		return 1;
	for(int i=2;i<=sqrt(n)+1;i++)
		if(!(n%i))
			return 0;
	return 1;
}
int main(){
	int n;
	cin>>n;
	bool first=1;
	for(int i=4;i<=n;i+=2){
		for(int k=2;k<=n;k++)
			if(prime(k)&&prime(i-k)){
				if(!first)
				cout<<endl;
				printf("%d=%d+%d",i,k,i-k);
				break;
			}
		if(first){
			first=0;
		}
	}
}