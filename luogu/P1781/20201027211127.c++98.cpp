#include<iostream>
using namespace std;
bool bj(string a,string b){
	if(a.length()>b.length())return 1;
	if(a.length()<b.length())return 0;
	if(a.length()==b.length())
	for(int i=0;i<=a.length();i++){
		if(a[i]>b[i])return 1;
		if(b[i]>a[i])return 0;
	}
}
int main(){
	string a[22];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	string maxx="0";
	int mxnum=0;
	for(int i=1;i<=n;i++){
		if(bj(a[i],maxx)){
			maxx=a[i];
			mxnum=i;
		}
//		cout<<i<<" "<<maxx<<" "<<a[i]<<endl;
	}
	cout<<mxnum<<endl<<maxx;
}