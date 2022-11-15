#include <stdio.h>
#include <memory.h>
#define maxn 800005
long long t[maxn];
template <class Type>
struct SegTree{
	int size;
	Type *data,*lazy;

	inline int __lc(int i) { return i << 1; }
	inline int __rc(int i) { return (i << 1) | 1; }
	SegTree(){
		data = new Type[maxn];
		lazy = new Type[maxn];
	}
	void init(int sizee,Type *dat){
		size=sizee;
		init(dat,1,size);
	}
	~SegTree(){
		delete[] data;
		delete[] lazy;
	}
	void updateNode(int __index)
	{
	    data[__index] = data[__lc(__index)] + data[__rc(__index)];
	}
	void setLazy(int index,Type value,int l,int r)
	{
	    data[index] += value * (r - l + 1);
	    lazy[index] += value;
	}
	void updateLazy(int index,int l,int r)
	{
	    int mid = (l + r) >> 1;
	    setLazy(__lc(index), lazy[index], l, mid);
	    setLazy(__rc(index), lazy[index], mid + 1, r);
	    lazy[index] = 0;
	}
	void init(Type *initialData,int left=1,int right=-114,int __index = 1)
	{
//		printf("SIZE %d\n",this->size);
	    if (right == -114)
	        right = this->size;
	    if (left == right)
	    {
	        data[__index] = initialData[left];
//	        size = __index > size ? __index : size;
	        return;
	    }
	    int mid = (left + right) >> 1;
	    init(initialData,left,mid,__lc(__index));
	    init(initialData,mid + 1,right,__rc(__index));
	    updateNode(__index);
	}
	void update(int left,int right,Type value,int __l = 1,int __r = -114,int __index = 1)
	{
//		printf("SIZE %d\n",this->size);
	    if (__r == -114)
	        __r = this->size;
	    if (__r < left || __l > right)
	        return;
	    if (left <= __l && __r <= right)
	    {
	        setLazy(__index, value, __l, __r);
//	        printf("- %d %d %d + %d\n",__l,__r,__index,value);
	        return;
	    }
	    int mid = (__l + __r) >> 1;
	    this->update(left, right, value, __l, mid, __lc(__index));
	    this->update(left, right, value, mid + 1, __r, __rc(__index));
	    updateLazy(__index, __l, __r);
	    updateNode(__index);
	}
	Type query(int left,int right,int __l = 1,int __r = -114,int __index = 1)
	{
//		printf("SIZE %d\n",this->size);
		if (__r == -114)
	        __r = this->size;
//		printf("- %d %d %d\n",__l,__r,__index);
	    updateLazy(__index, __l, __r);
	    if (__r < left || __l > right)
	        return Type(0);
	    if (left <= __l && __r <= right){
//			printf("- %d %d %d = %d\n",__l,__r,__index,data[__index]);
	        return data[__index];
		}
	    int mid = (__l + __r) >> 1;
	    Type sum = Type(0);
	    sum += query(left, right, __l, mid, __lc(__index));
	    sum += query(left, right, mid + 1, __r, __rc(__index));
	    return sum;
	}
	void __Debug(){
		for(int i=1;i<=20;i++)
			printf("%d ",data[i]+lazy[i]);
		puts("");
	}
};
int n, m, size,mode, x, y;
long long k;
SegTree<long long> seg;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", t + i);
    seg.init(n,t);
	seg.size = n;
//	seg.__Debug();
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &mode);
        if (mode == 1)
        {
            scanf("%d%d%lld", &x, &y, &k);
            seg.update(x, y, k);
        }
        else
        {
            scanf("%d%d", &x, &y);
            printf("%lld\n", seg.query(x, y));
        }
//        seg.__Debug();
    }
    return 0;
}
/*
15
10    5
6   4   2   3
1 5
*/