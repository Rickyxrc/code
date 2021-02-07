#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	scanf("%d/%d",&a,&b);
	scanf("%d/%d",&c,&d);
	int tp,tp_,tp__;
	tp__=__gcd(a*c,b*d);
	tp=(a*c)/tp__;
	tp_=(b*d)/tp__;
	int fm=1,fz=1,type=2;
	cout<<tp_<<" "<<tp; 
	return 0;
}