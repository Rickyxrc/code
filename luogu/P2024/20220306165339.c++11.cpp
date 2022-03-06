#include<stdio.h>
#define maxn 50005
int fn[maxn],hn[maxn];
int ff(int x){
	int sx = fn[x];
	if(sx!=x){
		fn[x] = ff(fn[x]);
		hn[x] = (hn[x] + hn[sx]) % 3; 
	}
	return fn[x];
}
bool merge(int x,int y,int op){
	int fx = ff(x);
	int fy = ff(y);
	if(fx!=fy){
		fn[fx] = fy;
		hn[fx] = (3+hn[y]+op-hn[x])%3;
	}	
	ff(x);ff(y);
	return (3+hn[x]-hn[y])%3!=op;
}
int n,k,t1,t2,t3,ans;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		fn[i] = i;
	for(int i=1;i<=k;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		if(t2 < 1 || t3 < 1 || t2 > n || t3 > n)ans++;
		else ans+=merge(t2,t3,t1-1);
	}
	printf("%d",ans);
	return 0;
}