#include<stdio.h>
#include<cmath>
#define maxn 1000007
using namespace std;
int sttable[maxn][21];
int n,tp,m,len,tpl,tpr,tppp,l2n;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
inline int min(int x,int y){return x<y?x:y;}
inline void glrmin(int l,int r){
	len=log2(r-l+1),
	tppp=min(sttable[l][len],sttable[r-(1<<len)+1][len]),
	printf("%d\n",tppp);
}
int main(){
	n=read();
	m=read();
	for(register int i=0;i<n;i++){
		sttable[i][0]=read();
	}
	l2n = log2(n);
	for(register int i=1;i<=l2n;i++){
		for(register int j=0;j<n;j++)
			sttable[j][i]=min(sttable[j][i-1],sttable[j+(1<<(i-1))][i-1]);
	}
	for(int i=0;i<n-m+1;i++)
	{
//		printf("(%d,%d)\n",i,m+i-1);
		glrmin(i,m+i-1);
	}
		
	
	return 0;
}