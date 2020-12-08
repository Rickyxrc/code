#include<bits/stdc++.h>
using namespace std;
int main()
{
	int top=0;
	char c;
	do
	{
		cin.get(c);
		if(c=='[')top++;
		else if(c==']')top--;
		else if(c=='(')top++;
		else if(top==0&&(c==')'||c==']')){
			cout<<"NO";
			return 0;
		}
		else if(c==')')top--;
	}
	while(c!='@');
	if(top==0)cout<<"YES";
	else cout<<"NO";
}