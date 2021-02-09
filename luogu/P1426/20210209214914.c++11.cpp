#include<bits/stdc++.h>;
using namespace std;
int main(){
	double ind,x,k=7,n;
	cin>>ind>>x;
	for(int i=1;;i++,n+=k,k*=0.98)
		if(n>=ind-x)
			if(n+k*0.98>ind+x){
				cout<<"n";
				return 0;
			}
			else{
				cout<<"y";
				return 0;
			}
	return 0;
}