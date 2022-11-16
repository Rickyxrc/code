#include<stdio.h>
#include<vector>
#include<memory.h>

int modnum;

namespace Seg{
	#define maxn 400005
	long long data[maxn], lazy[maxn], t[maxn / 4] , t_indexed[maxn/4];
	int n, m, size;
	inline long long __lc(long long i) { return i << 1; }
	inline long long __rc(long long i) { return __lc(i) | 1; }
	void updateNode(long long __index)
	{
	    data[__index] = (data[__lc(__index)] + data[__rc(__index)]) % modnum;
	}
	void setLazy(long long index, long long value, long long l, long long r)
	{
		value %= modnum;
	    data[index] += value * (r - l + 1);
	    data[index] %= modnum;
	    lazy[index] += value;
	    lazy[index] %= modnum;
	}
	void updateLazy(long long index, long long l, long long r)
	{
	    int mid = (l + r) >> 1;
	    setLazy(__lc(index), lazy[index], l, mid);
	    setLazy(__rc(index), lazy[index], mid + 1, r);
	    lazy[index] = 0;
	}
	void initSegmentTree(long long left, long long right, long long *initialData, long long __index = 1)
	{
	    if (left == right)
	    {
	        data[__index] = initialData[left];
	        return;
	    }
	    long long mid = (left + right) >> 1;
	    initSegmentTree(left, mid, initialData, __lc(__index));
	    initSegmentTree(mid + 1, right, initialData, __rc(__index));
	    updateNode(__index);
	}
	void updateSegment(long long left, long long right, long long value, long long __l = 1, long long __r = -114, long long __index = 1)
	{
	    if (__r == -114)
	        __r = n;
	    if (__r < left || __l > right)
	        return;
	    if (left <= __l && __r <= right)
	    {
	        setLazy(__index, value, __l, __r);
	        return;
	    }
	    updateLazy(__index, __l, __r); // 
	    long long mid = (__l + __r) >> 1;
	    updateSegment(left, right, value, __l, mid, __lc(__index));
	    updateSegment(left, right, value, mid + 1, __r, __rc(__index));
	    updateNode(__index);
	}
	long long querySegment(long long left, long long right, long long __l = 1, long long __r = -114, long long __index = 1)
	{
	    if (__r == -114)
	        __r = n;
	    if (__r < left || __l > right)
	        return 0;
	    if (left <= __l && __r <= right)
	        return data[__index];
	    updateLazy(__index, __l, __r);
	    long long mid = (__l + __r) >> 1;
	    long long sum = 0;
	    sum += querySegment(left, right, __l, mid, __lc(__index)) % modnum;
	    sum += querySegment(left, right, mid + 1, __r, __rc(__index)) % modnum;
	    return sum % modnum;
	}
	
	#undef maxn

}

namespace treecut{
	#define maxn 500007 
	
	std::vector<int> edge[maxn];
	
	int s,x,y,liancnt;
	
	int deps[maxn],fa[maxn],size[maxn],hson[maxn],top[maxn],rev[maxn],id[maxn];
	
	void first_dfs(int index,int fath){
		deps[index] = deps[fath]+1;
		fa[index] = fath;
		size[index] = 1;
		for(auto s:edge[index]){
			if(s == fath)continue;
			first_dfs(s,index);
			size[index] += size[s];
			if(size[hson[index]] < size[s])
				hson[index] = s;
		}
	}
	
	void treecut(int index,int topp){
		top[index] = topp;
		id[index] = ++liancnt;
		rev[liancnt] = index;
		if(hson[index] == 0)return;
		treecut(hson[index],topp);
		for(auto s:edge[index])
			if(s!=hson[index] && s!=fa[index])
				treecut(s,s);
	}
	
	#undef maxn
}

namespace solve{
	inline long long mindp(long long a,long long b){
		return treecut::deps[a]<treecut::deps[b]?a:b;
	}
	
	inline long long queryTree(long long x,long long mod){return Seg::querySegment(treecut::id[x],treecut::id[x] + treecut::size[x] - 1)%mod;}
	inline long long addTree(long long x,long long y){Seg::updateSegment(treecut::id[x],treecut::id[x] + treecut::size[x] - 1,y);}
	
	inline void chainadd(long long x,long long y,long long val){
		if(treecut::deps[x]>treecut::deps[y])
			Seg::updateSegment(treecut::id[y],treecut::id[x],val);
		else
			Seg::updateSegment(treecut::id[x],treecut::id[y],val);
	}
	
	inline long long chainquery(long long x,long long y){
		if(treecut::deps[x]>treecut::deps[y])
			return Seg::querySegment(treecut::id[y],treecut::id[x]) % modnum;
		else
			return Seg::querySegment(treecut::id[x],treecut::id[y]) % modnum;
	}

	inline void add(long long a,long long b,long long val){
		while(treecut::top[a] != treecut::top[b]){
			if(treecut::deps[treecut::top[a]] > treecut::deps[treecut::top[b]])
				chainadd(treecut::top[a],a,val),
				a = treecut::fa[treecut::top[a]];
			else
				chainadd(treecut::top[b],b,val),
				b = treecut::fa[treecut::top[b]];
		}
		
		chainadd(a,b,val);
		return;
	}
	
	inline long long querychain(long long a,long long b){
		long long ans=0;
		while(treecut::top[a] != treecut::top[b]){
			if(treecut::deps[treecut::top[a]] > treecut::deps[treecut::top[b]]){
				ans += chainquery(treecut::top[a],a) % modnum;
				a = treecut::fa[treecut::top[a]];
			}
			else{
				ans += chainquery(treecut::top[b],b) % modnum;
				b = treecut::fa[treecut::top[b]];
			}
		}
		
		ans += chainquery(a,b) % modnum;
		return ans % modnum;
	}
}
long long n,m,s,x,y,r,p,mode,z;

signed main(){
	scanf("%lld%lld%lld%lld",&n,&m,&r,&p);
	modnum = p;
	
	for(long long i=1;i<=n;i++){
		scanf("%lld",&Seg::t[i]);
	}
	Seg::n=n;
	
	
	for(long long i=1;i<n;i++)
		scanf("%lld%lld",&x,&y),
		treecut::edge[x].push_back(y),
		treecut::edge[y].push_back(x);
	
	memset(treecut::deps,0x3f,sizeof(treecut::deps));
	s = r;

	treecut::deps[s]=0;
	
	treecut::first_dfs(s,s);
	treecut::treecut(s,s);
	
	for(long long i=1;i<=n;i++)
		Seg::t_indexed[i] = Seg::t[treecut::rev[i]];
	
	Seg::initSegmentTree(1,n,Seg::t_indexed);
	
	for(long long i=1;i<=m;i++){
		scanf("%lld",&mode);
		if(mode==1){
			scanf("%lld%lld%lld",&x,&y,&z);
			solve::add(x,y,z);
		}
		if(mode==2){
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",solve::querychain(x,y) % modnum);
		}
		if(mode==3){
			scanf("%lld%lld",&x,&y);
			solve::addTree(x,y);
		}
		if(mode==4){
			scanf("%lld",&x);
			printf("%lld\n",solve::queryTree(x,p) % modnum);
		}
	}
	return 0;
}

/*
6 100 1 100000
1 2 3 4 5 6
1 2
1 3
2 4
3 5
2 6
*/
/*
8 10 2 448348
458 718 447 857 633 264 238 944 
1 2
2 3
3 4
6 2
1 5
5 7
8 6
3 7 611
4 6
3 1 267
3 2 111
1 6 3 153
3 7 673
4 8
2 6 1
4 7
3 4 228
*/