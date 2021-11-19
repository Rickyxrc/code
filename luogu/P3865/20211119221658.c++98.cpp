#include<bits/stdc++.h>
using namespace std;
unsigned int dp[300002][75],lgg[200002];
//inline int max(const int& a,const int& b){
//	return (a>b)?a:b;
//}
inline const int read()
{
	int x=0;char ch=getchar();
	while (!isdigit(ch)){ch=getchar();}
	while (isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x;
}
int n,tp,m,len,tpl,tpr,tppp;
int main(){
	n=read();
	m=read();
	lgg[0]=-1;
	dp[0][0]=read();
	for(register int i=1;i<n;i++)
		dp[i][0]=read(),
			lgg[i]=lgg[i/2]+1;
	lgg[n]=lgg[n/2]+1;
	for(register int i=1;i<lgg[n]+1;i++)
		for(register int j=0;j<n;j++)
			dp[j][i]=max(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
	lgg[0]=0;
	for(register int i=0;i<m;i++){
		tpl=read()-1,
		tpr=read()-1,
		len=lgg[tpr-tpl+1],
		tppp=max(dp[tpl][len],dp[tpr-(1<<len)+1][len]),
		printf("%d\n",tppp);
	}
	return 0;
}