#include<stdio.h>
#include<map>
using std::map;
#define maxn 1000006
int t[maxn],n,tot,tp1[maxn],tp2[maxn],cnt;
map<int,int> mp;
int mapto(int tt){
	if(mp.find(tt)==mp.end()){
		mp[tt]=++tot;
		t[tot]=tot;
		return tot;
	}
	return mp[tt];
}
inline int findf(int n){return t[n]=((t[n]==n)?n:findf(t[n]));}
void merge(int i,int j){
	i=findf(i);
	j=findf(j);
	t[i]=j;
}
int T,t1,t2,t3,f;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		cnt=0;
		f=1;
		mp.clear();
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&t1,&t2,&t3);
			
			if(!f)
				continue;
			
			t1 = mapto(t1);
			t2 = mapto(t2);
			
			if(t3==1)
				merge(t1,t2);
			if(t3==0){
				if(findf(t1) == findf(t2))
					f=0;
				tp1[cnt] = t1,
				tp2[cnt++] = t2;
			}
		}
		if(f)
			for(int i=0;i<cnt;i++)
				if(findf(tp1[i]) == findf(tp2[i])){
					f=0;
					break;
				}
			
		if(f==1)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}