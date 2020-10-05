#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[15],num=0;
	cin>>a;
	for(int i=0;i<=8;i++)num+=(a[i]=='1');
	cout<<char(num+'0');
	return 0;
}