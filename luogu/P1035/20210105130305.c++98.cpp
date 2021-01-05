#include<bits/stdc++.h>
using namespace std; 
int main(){
	double s=1;
	int k=-1;
	cin>>k;
	int i=1;
	while(s<=k)
		s+=1/double(i+++1);
	cout<<i;
	return 0;
}