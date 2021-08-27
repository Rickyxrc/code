#include<stdio.h>
#include<ctype.h>

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int cup[1<<9],val[1<<9],n,cnt=1,num;
int main(){
	n=read();
	n=1<<n;
	for(int i=1;i<=n;i++)
		val[i]=read();
	num=(n<<1)-1;
	for(int i=(num>>1)+1;i<=num;i++)
		cup[i]=cnt++;
	for(int i=num>>1;i>=1;i--)
		if(val[cup[(i<<1)]] > val[cup[(i<<1)|1]])
			cup[i]=cup[(i<<1)];
		else
			cup[i]=cup[(i<<1)|1];
	if(cup[2] == cup[1])
		printf("%d",cup[3]);
	else
		printf("%d",cup[2]);
	return 0;
}