#include<bits/stdc++.h>
using namespace std;
string boys[6]={"boy","oy","bo","y","b","o"};
int boysize[6]={3,2,2,1,1,1};
string girls[10]={"girl","gir","irl","ir","rl","gi","l","g","r","i"};
int girlsize[10]={4,3,3,2,2,2,1,1,1,1};
int boynum=0,girlnum=0;
string sum="";
bool search_boy()
{
	bool flaga=0;
	for(int i=0;i<=5;i++)
	if(sum.find(boys[i])!=string::npos)
	{
		boynum++;
//		cout<<sum<<endl;
		sum.replace(sum.find(boys[i]),boysize[i],".");
		flaga=1;
//		cout<<sum<<endl;
//		cout<<"boy:"<<boynum<<endl;
		break;
	}

	return flaga;	
}
bool search_girl()
{
	bool flagb=0;
	for(int i=0;i<=9;i++)
	if(sum.find(girls[i])!=string::npos)
	{
//		cout<<sum<<endl;
		girlnum++;
		sum.replace(sum.find(girls[i]),girlsize[i],".");
		flagb=1;
//		cout<<sum<<endl;
//		cout<<"girl:"<<girlnum<<endl;
		break;
	}

	return flagb;
}
int main()
{
	cin>>sum;
	bool a=1,b=1;
	do
	{
	a=search_boy();
	b=search_girl();
	}
	while(a||b);
	cout<<boynum<<endl<<girlnum; 
}