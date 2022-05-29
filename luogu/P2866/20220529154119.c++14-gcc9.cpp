#include<stdio.h>
#include<stack>
#define maxn 100007
#define int long long
int anss[maxn],dat[maxn],tmpstack[maxn],n,top,s;
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&dat[i]);
	}
	for(int i=n;i>=1;i--){
		while(top>0&&dat[i]>dat[tmpstack[top]])top--;
		tmpstack[++top]=i;
		anss[i]=tmpstack[top-1];
		if(anss[i]!=0)
			s+=anss[i]-i-1;
		else
			s+=n-i;
		
	}
	printf("%lld",s);
	return 0;
}