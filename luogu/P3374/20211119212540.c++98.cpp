#include<stdio.h>
typedef long long T;
T lowbit(T x){
	return x&-x;
}
#define maxn 500005
struct szsz{
	T k[maxn],size;
	void add(int ind,int n){
		while(ind<=size){
			k[ind]+=n;
			ind+=lowbit(ind);
		}
	}
	T query1(T ind){
		T ans=0;
		while(ind>0){
			ans+=k[ind];
			ind-=lowbit(ind);
		}
		return ans;
	}
	T euq(int i,int j){
		return query1(j)-query1(i-1);
	}
};
long long n,m,tp1,tp2,tp3;

szsz t;
int main(){
	scanf("%lld%lld",&t.size,&m);
	for(int i=1;i<=t.size;i++)
		scanf("%lld",&tp1),
		t.add(i,tp1);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&tp1,&tp2,&tp3);
		if(tp1==1){
			t.add(tp2,tp3);
		}
		else
			printf("%lld\n",t.euq(tp2,tp3));
	}
	return 0;
}