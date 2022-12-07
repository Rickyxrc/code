#include<stdio.h>

#define int long long
#define maxn 200007

int data[maxn<<2],lazy[maxn<<2],li[maxn];
int n,m,mode,x,y,z;

#define ls(index) (index<<1)
#define rs(index) (index<<1|1)
#define mid ((l+r)>>1)

#define lseq ls(index),l,mid
#define rseq rs(index),mid+1,r
#define seqq index,l,r

inline void update(int index){data[index] = data[ls(index)] + data[rs(index)];}
inline void setlazy(int index,int l,int r,int val){data[index] += val * (r-l+1);lazy[index] += val;}

inline void pushdown(int index,int l,int r){
	setlazy(lseq,lazy[index]);
	setlazy(rseq,lazy[index]);
	lazy[index]=0;
}

void init(int index=1,int l=1,int r=n){
//	printf("%d %d %d\n",index,l,r);
	if(l==r){
		data[index] = li[l];
		return;
	}
	init(lseq);
	init(rseq);
	update(index);
}

void add(int x,int y,int val,int index=1,int l=1,int r=n){
	pushdown(seqq);
	if(x<=l && r<=y){
		setlazy(seqq,val);
		return;
	}
	if(r<x || l>y)
		return;
	add(x,y,val,lseq);
	add(x,y,val,rseq);
	update(index);
}

int query(int x,int y,int index=1,int l=1,int r=n){
	pushdown(seqq);
	if(x<=l && r<=y){
		return data[index];
	}
	if(r<x || l>y)
		return 0;
	return
		query(x,y,lseq)+
		query(x,y,rseq);
}

signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",li+i);
		
	init();
		
	for(int i=1;i<=m;i++){
		scanf("%lld",&mode);
		if(mode == 1){
			scanf("%lld%lld%lld",&x,&y,&z);
			add(x,y,z);
		}
		if(mode == 2){
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",query(x,y));
		}
	}
	return 0;
}