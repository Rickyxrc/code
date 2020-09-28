#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool flag[105],a=1;
	int n,m,x=0;
	cin>>n>>m;
	for(int i=0;i<=102;i++)flag[i]=1;
	int count=0,num=0;
	while(1)
	{
		num++;
		if(flag[num])count++;
		if(count==m)
		{
			flag[num]=0;
			count=0;
			if(!a)cout<<' '<<num;
			else cout<<num;
			x++;
			a=0;
		}
		if(x==n)break;
		num=num%n;
		count=count%m;
	}
	return 0;
}