#include<iostream>
using namespace std;
bool prime(int n){
	for(int i=2;i<n;i++)
	if(n%i==0)
	return 0;
	return 1;
}
int find_prime(int x){
	for(int i=2;i<=x;i++)
		if(prime(i)&&x%i==0)
			return i;
	return 0;
}
int main(){
	int a;
	cin>>a;
	cout<<(a/find_prime(a));
	return 0;
}