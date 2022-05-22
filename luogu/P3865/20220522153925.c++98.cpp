#include<stdio.h>
#define maxn 300007
using namespace std;
int sttable[maxn][75],lgg[maxn];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
inline int max(int x,int y){return x>y?x:y;}
int n,tp,m,len,tpl,tpr,tppp;
int main(){
	n=read();
	m=read();
	lgg[0]=-1;
	sttable[0][0]=read();
	for(register int i=1;i<n;i++)
		sttable[i][0]=read(),
			lgg[i]=lgg[i>>1]+1;
	lgg[n]=lgg[n>>1]+1;
	for(register int i=1;i<lgg[n]+1;i++)
		for(register int j=0;j<n;j++)
			sttable[j][i]=max(sttable[j][i-1],sttable[j+(1<<(i-1))][i-1]);
	lgg[0]=0;
	for(register int i=0;i<m;i++){
		tpl=read()-1,
		tpr=read()-1,
		len=lgg[tpr-tpl+1],
		tppp=max(sttable[tpl][len],sttable[tpr-(1<<len)+1][len]),
		printf("%d\n",tppp);
	}
	return 0;
}