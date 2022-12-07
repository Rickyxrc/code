#include<stdio.h>

#define int long long
#define maxn 200007

int n,m,x,y,z,mode;

int li[maxn],data[maxn<<2],lazy[maxn<<2];

inline int ls(int index){return index<<1;}
inline int rs(int index){return ls(index)|1;}
inline int gmid(int l,int r){return (l+r)>>1;}
inline void update(int index){data[index] = data[ls(index)] + data[rs(index)];}
inline void setlazy(int index,int l,int r,int val){data[index] += val*(r-l+1);lazy[index] += val;}

inline void push(int index,int l,int r){
	int mid = gmid(l,r);
	setlazy(ls(index),l,mid,lazy[index]);
	setlazy(rs(index),mid+1,r,lazy[index]);
	lazy[index] = 0;
}


void init(int l,int r,int index){
	if(l==r){
		data[index] = li[l];
		return;
	}
	int mid = gmid(l,r);
	init(l,mid,ls(index));
	init(mid+1,r,rs(index));
	update(index);
}

void add(int x,int y,int val,int index,int l,int r){
	push(index,l,r);
	if(x<=l && r<=y){
		setlazy(index,l,r,val);
		return;
	}
	if(r < x || l > y)
		return;
	int mid = gmid(l,r);
	add(x,y,val,ls(index),l,mid);
	add(x,y,val,rs(index),mid+1,r);
	update(index);
}

int query(int x,int y,int index,int l,int r){
	push(index,l,r);
	if(x<=l && r<=y)
		return data[index];
	if(r < x || l > y)
		return 0;
	int mid = gmid(l,r);
	return query(x,y,ls(index),l,mid)+
		query(x,y,rs(index),mid+1,r);
}

signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",li+i);
	init(1,n,1);
	for(int i=1;i<=m;i++){	
		scanf("%lld",&mode);
		if(mode==1)
			scanf("%lld%lld%lld",&x,&y,&z),
			add(x,y,z,1,1,n);
		if(mode==2)
			scanf("%lld%lld",&x,&y),
			printf("%lld\n",query(x,y,1,1,n));
	}
}