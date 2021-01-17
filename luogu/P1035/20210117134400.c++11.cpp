#include<bits/stdc++.h>
using namespace std;
int main(){
	double s=0,i=1;
	int m;
	cin>>m;
	if(m==1){
		cout<<2;
		return 0;
	}
	while(s<m)
		s+=double(1.00/i),i++;
	cout<<int(i-1);
	return 0;
}