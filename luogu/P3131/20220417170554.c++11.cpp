#include<stdio.h>
#define maxn 50006
int prefix[maxn],n,t,fi,st,ed,mxx;
int maxx(int ii,int jj){return ii>jj?ii:jj;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&prefix[i]),
		prefix[i] = (prefix[i-1]+prefix[i])%7;
	
//	for(int i=1;i<=n;i++)
//		printf("[%d]",prefix[i]);
	
	for(int i=0;i<7;i++){
		st=0;while(prefix[st]!=i&&st<=n)st++;
		ed=n;while(prefix[ed]!=i&&ed>=0)ed--;
		mxx = maxx(ed-st,mxx);
//		printf("%d\n",mxx);
	}
	
	printf("%d",mxx);
	
	return 0;
}