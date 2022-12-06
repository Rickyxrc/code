#include<stdio.h>
#define int long long

const int maxn = 1000000 + 7;

int data[maxn<<2],lazy[maxn<<2],li[maxn];

void update(int _index){
	data[_index] = data[_index<<1] + data[(_index<<1)|1];
}

void init(int l,int r,int _index){
	if(l==r){
		data[_index] = li[l];
		return;
	}
	int mid = (l+r)>>1;
	init(l,mid,_index<<1);
	init(mid+1,r,_index<<1|1);
	update(_index);
}

void setlazy(int index,int val,int l,int r){
	data[index] += val*(r-l+1);
	lazy[index] += val;
}
void pushdown(int index,int l,int r){
	int mid = (l+r)>>1;
	setlazy(index<<1,lazy[index],l,mid);
	setlazy(index<<1|1,lazy[index],mid+1,r);
	lazy[index]=0;
}

void add(int x,int y,int val,int l,int r,int index){
	pushdown(index,l,r);
	if(r<x || l>y)
		return;
	if(x<=l&&r<=y){
		setlazy(index,val,l,r);
		return;
	}
	int mid = (l+r)>>1;
	add(x,y,val,l,mid,index<<1);
	add(x,y,val,mid+1,r,index<<1|1);
	update(index);
}

int query(int x,int y,int l,int r,int index){
//	printf("now %d %d\n",l,r);
	
	pushdown(index,l,r);
	if(r<x || l>y)
		return 0;
	if(x<=l&&r<=y)
		return data[index];
	
	int mid = (l+r)>>1,ans=0;
	ans += query(x,y,l,mid,index<<1);
	ans += query(x,y,mid+1,r,index<<1|1);
	return ans;
}

int n,m,mode,x,y,z;
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",li+i);
	init(1,n,1);
	
	for(int i=1;i<=m;i++){	
		scanf("%lld",&mode);
		if(mode==1){
			scanf("%lld%lld%lld",&x,&y,&z);
			add(x,y,z,1,n,1);
		}
		if(mode==2){
			scanf("%lld%lld",&x,&y,&z);
			printf("%lld\n",query(x,y,1,n,1));
		}
	}
	return 0;
}