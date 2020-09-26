#include<bits/stdc++.h>
using namespace std;
int zh(char a)
{
	int s;
	if(a>='0'&&a<='9')
	{
		s=a-'0';
	}
	if(a>='A'&&a<='F')
	{
		s=a-'A'+10;
	}
	return s;
}
char zha(int a)
{
	char s;
	if(a>=0&&a<=9)
	{
		s=a+'0';
	}
	if(a>=10&&a<=15)
	{
		s=a+'A'-10;
	}
	return s;
}
int main()
{
	string a;
	int s=0;
	int jz;
	cin>>jz;
	cin>>a;
	string ans="";
	for(int i=0;i<a.length();i++)
	{
		s=(s*jz+zh(a[i]));
	}
//	cout<<s<<endl;
	cin>>jz;
	if(a=="0")
	{
		cout<<0;
		return 0;
	}
	while(s)
	{
		ans=zha(s%jz)+ans;
		s=s/jz;
//		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}