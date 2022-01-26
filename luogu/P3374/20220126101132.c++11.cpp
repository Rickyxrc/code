#include<stdio.h>
#define maxn 500005
int t[maxn];
inline int lowbit(int x){return x&-x;}
inline void add(int ind,int x){
	while(ind<=maxn)
		t[ind]+=x,
		ind+=lowbit(ind);
	return;
}
inline int queryl(int n){
	int ans=0;
	while(n>0)
		ans+=t[n],
		n-=lowbit(n);
	return ans;
}
inline int query(int l,int r){
	return queryl(r)-queryl(l-1);
}
int n,m,tp,tp2,tp3;
void init(){
	for(int i=1;i<=n;i++)
		scanf("%d",&tp),
		add(i,tp);
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&tp,&tp2,&tp3);
		if(tp == 1)
			add(tp2,tp3);
		else
			printf("%d\n",query(tp2,tp3));
	}
	return 0;
}