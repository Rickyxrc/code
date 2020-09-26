#include<bits/stdc++.h>
using namespace std;
int ltn(char a)
{
	int s;
	if(a>='0'&&a<='9')
	{
		s=a-'0';
	}
	if(a>='A'&&a<='Z')
	{
		s=a-'A'+10;
	}
	return s;
}
char ntl(int a)
{
	char s;
	if(a>=0&&a<=9)
	{
		s=a+'0';
	}
	if(a>=10&&a<=36)
	{
		s=a+'A'-10;
	}
	return s;
}
int main()
{
	int a,c=0,ls1,ls2,t;
	string stra,strb,ans;
	cin>>a>>stra>>strb;
	int la=stra.length(),lb=strb.length();
	int maxlen=max(la,lb);
	for(int i=1;i<=maxlen;i++)
	{
		ls1=0;ls2=0;
		if(i<=la) ls1=ltn(stra[la-i]);
		if(i<=lb) ls2=ltn(strb[lb-i]);
		t=(ls1+ls2+c)%a;
		ans=ntl(t)+ans;
		c=(ls1+ls2+c)/a;
	}
	while(c)
	{
		t=c%a;
		c=c/a;
		ans=ntl(t)+ans;
	}
	cout<<ans;
}