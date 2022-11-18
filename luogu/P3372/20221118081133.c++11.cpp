#include<stdio.h>
#define int long long
int t[600007],lazy[600007],dat[200007],n,m,mode,u,l,r;

inline int gmid(int l,int r){return (l+r)>>1;}
inline int ls (int i){return i<<1;}
inline int rs (int i){return (i<<1)|1;}
inline void updateNode(int i){t[i] = t[ls(i)] + t[rs(i)];}
inline void setlazy(int index,int l,int r,int val){lazy[index] += val;t[index] += val * (r-l+1);}
inline void pushdownLazy(int index,int l,int r){int mid = gmid(l,r);setlazy(ls(index),l,mid,lazy[index]);setlazy(rs(index),mid+1,r,lazy[index]);lazy[index] = 0;}
void buildSegmentTree(int l,int r,int index){
	if(l==r){
		t[index] = dat[l];
		return;
	}
	int mid = gmid(l,r);
	buildSegmentTree(l,mid,ls(index));
	buildSegmentTree(mid+1,r,rs(index));
	updateNode(index);
}

void updateSegment(int le,int ri,int val,int index,int __l,int __r){
	if(__l > ri || __r < le)
		return;
	if(le <= __l && __r <= ri){
		setlazy(index,__l,__r,val);
		return;
	}
	int mid=gmid(__l,__r);
	updateSegment(le,ri,val,ls(index),__l,mid);
	updateSegment(le,ri,val,rs(index),mid+1,__r);
	pushdownLazy(index,__l,__r);
	updateNode(index);
}

int querySegment(int le,int ri,int index,int __l,int __r){
	pushdownLazy(index,__l,__r);
	if(__l > ri || __r < le)
		return 0;
	if(le <= __l && __r <= ri)
		return t[index];
	int mid=gmid(__l,__r),ans=0;
	ans+=querySegment(le,ri,ls(index),__l,mid);
	ans+=querySegment(le,ri,rs(index),mid+1,__r);
	return ans;
}


signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&dat[i]);
	buildSegmentTree(1,n,1);
	for(int i=1;i<=m;i++){
		scanf("%lld",&mode);
		if(mode==1){
			scanf("%lld%lld%lld",&l,&r,&u);
			updateSegment(l,r,u,1,1,n);
		}
		else {
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",querySegment(l,r,1,1,n));
		}
	}
	return 0;
}