#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cctype>

using namespace std;

__int128 n;
__int128 qz[10007];
__int128 dp[10007][10007];

__int128 read(){
	__int128 t=0;char c;int sig=1;
	c = getchar();
	while(!isdigit(c)){
		if(c == '-')
			sig*=-1;
		c = getchar();
	}
	while( isdigit(c))
		t = (t<<1) + (t<<3) + (c^48),
		c = getchar();
	return t*sig;
}

void print(__int128 t){
	if(t<0){
		putchar('-');
		print(-t);
		return;
	}
	if(t>9)
		print(t/10);
	putchar(t%10+48);
	return;
}

__int128 min(__int128 a,__int128 b){
	return a<b?a:b;
}

int main()
{
	print(read()+read());
//	for(__int128 i=1;i<=100;i++)
//		for(__int128 j=1;j<=100;j++)
//			dp[i][j] = 99999999999999;
//		
//	n = read();
//	for(__int128 i=1;i<=n;i++)
//		qz[i] = read();
//	for(__int128 i=n;i>=1;i--)
//		for(__int128 j=i+1;j<=n;j++)
//            	{
//					if(j-i==1)//容不下一个三角形（参见上述错误。）
//						dp[i][j]=0;
//					else if(j-i==2)
//		                dp[i][j]=qz[i]*qz[i+1]*qz[i+2];//因为此时i和j中间只剩一个顶点了所以直接计算即可
//		            else
//		            	for(__int128 k=i+1;k<=j-1;k++)
//		            	{
//		            		dp[i][j]=min(dp[i][j],(dp[i][k]+dp[k][j]+qz[i]*qz[j]*qz[k]));
//						}
//				}
//	
//	printf("%lld",dp[1][n]);
	return 0;
}