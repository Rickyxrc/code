#include<iostream>
using namespace std;
int main(){
	long long a=1,b=1;
	string aa,bb;
	cin>>aa>>bb;
	for(int i=0;i<aa.length();i++){
		a*=(aa[i]-'A'+1);
	}
	for(int i=0;i<bb.length();i++){
		b*=(bb[i]-'A'+1);
	}
	if(a%47==b%47)
		cout<<"GO";
	else
		cout<<"STAY";
	return 0;
}