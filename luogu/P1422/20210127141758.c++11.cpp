#include<bits/stdc++.h>
using namespace std;
int main(){
	int en;
	cin>>en;
	double prs;
	for(int i=1;i<=150&&en;i++){
		en--;
		prs+=0.4463;
	}
	for(int i=151;i<=400&&en;i++){
		en--;
		prs+=0.4663;
	}
	prs+=0.5663*(double)(en);
	
	cout<<fixed<<setprecision(1)<<prs;
	return 0;
}