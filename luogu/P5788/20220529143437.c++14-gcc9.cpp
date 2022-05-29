#include<stdio.h>
#include<stack>
#define maxn 3000007
int anss[maxn],dat[maxn],tmpstack[maxn],n,top;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&dat[i]);
	}
	for(int i=n;i>=1;i--){
		while(dat[i]>=dat[tmpstack[top]]&&top>0)top--;
		tmpstack[++top]=i;
//		printf("push\n");
		anss[i]=tmpstack[top-1];
	}
	for(int i=1;i<=n;i++)
		printf("%d ",anss[i]);
	return 0;
}