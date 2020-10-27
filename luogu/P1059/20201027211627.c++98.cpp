#include<iostream>
using namespace std;
int main(){
	bool book[1005]={0};
	int n;
	cin>>n;
	int m;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>m;
		if(book[m]==0)
		num++;
		book[m]=1;
	}
	cout<<num<<endl;
	for(int i=1;i<=1000;i++)if(book[i])cout<<i<<" ";
	return 0;
}