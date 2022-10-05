#include<bits/stdc++.h>
int pfix[1000007]={-1},ch,n,i=0,j=-1;
std::string str;
int main(){
	std::cin>>n>>str;
	while((i<str.length()))
		(j==-1||str[i]==str[j])?(pfix[++i]=++j):(j=pfix[j]);
	return 0&printf("%d",n-pfix[n]);
}