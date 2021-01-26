#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	double a,b;
	cin>>a>>b;
	double c;
	c=a/(b*b);
	if(c<18.5)
		cout<<"Underweight";
	else if(c>=18.5&&c<24)
		cout<<"Normal";
	else
		cout<<c<<endl<<"Overweight";
    return 0;
}