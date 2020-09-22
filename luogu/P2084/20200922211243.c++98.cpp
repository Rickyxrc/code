#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
string s;
cin>>s;
int a=s.length();
int i;
for(i=0;i<=s.length()-1;i++)
{
	if(s[i]!='0'&&n!='0')
	{
	if(i!=0)cout<<'+';
	cout<<s[i]<<'*'<<n<<'^'<<a-i-1;
	}
}
return 0;
}