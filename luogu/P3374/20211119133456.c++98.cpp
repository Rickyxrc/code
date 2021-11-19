#include<stdio.h>
long long lowbit(long long x){return x&-x;}

#define maxn 500005
struct Treenums{
	long long sz[maxn];
	int size;
	void add(long long ind,long long num){
		while(ind<=size){
			sz[ind]+=num;
			ind+=lowbit(ind);
		}
		return;
	}
	long long from1getsum(long long i){
		long long res = 0;
		while(i>0){
			res+=sz[i];
			i-=lowbit(i);
		}
		return res;
	}
	long long getnum(long long l,long long r){
		return from1getsum(r)-from1getsum(l-1);
	}
};
int n,m;
long long tp1,tp2,tp3;
Treenums t;
int main(){
	
	scanf("%d%d",&t.size,&m);
	for(int i=1;i<=t.size;i++){
		scanf("%d",&tp1);
		t.add(i,tp1);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&tp1,&tp2,&tp3);
		if(tp1 == 1)
			t.add(tp2,tp3);
		else if(tp1 == 2){
			printf("%lld\n",t.getnum(tp2,tp3));
		}
	}
	return 0;
}