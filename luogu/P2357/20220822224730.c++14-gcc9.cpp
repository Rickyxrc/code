#include <stdio.h>
#define maxn 800005
long long data[maxn], lazy[maxn], t[maxn / 4];
int n, m, size;
inline long long __lc(long long i) { return i << 1; }
inline long long __rc(long long i) { return __lc(i) | 1; }
void updateNode(long long __index)
{
    data[__index] = data[__lc(__index)] + data[__rc(__index)];
}
void setLazy(long long index, long long value, long long l, long long r)
{
    if (index > size)
        return;
    data[index] += value * (r - l + 1);
    lazy[index] += value;
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
    if (right == -114)
        right = n - 1;
    if (left == right)
    {
        data[__index] = initialData[left];
        size = __index > size ? __index : size;
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
    long long mid = (__l + __r) >> 1;
    updateSegment(left, right, value, __l, mid, __lc(__index));
    updateSegment(left, right, value, mid + 1, __r, __rc(__index));
    updateLazy(__index, __l, __r);
    updateNode(__index);
}
long long querySegment(long long left, long long right, long long __l = 1, long long __r = -114, long long __index = 1)
{
    if (__r == -114)
        __r = n;
    updateLazy(__index, __l, __r);
    if (__r < left || __l > right)
        return 0;
    if (left <= __l && __r <= right)
        return data[__index];
    long long mid = (__l + __r) >> 1;
    long long sum = 0;
    sum += querySegment(left, right, __l, mid, __lc(__index));
    sum += querySegment(left, right, mid + 1, __r, __rc(__index));
    return sum;
}
int mode, x, y, k;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", t + i);
    initSegmentTree(1, n, t);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", &mode);
        if (mode == 1)
        {
            scanf("%lld%lld%lld", &x, &y,&k);
            updateSegment(x, y, k);
        }
        else if(mode==2)
        {
            scanf("%lld", &x);
            updateSegment(1,1, x);
        }
        else if(mode==3){
            scanf("%lld", &x);
            updateSegment(1,1, -x);
        }
        else if(mode==4){
            scanf("%lld%lld", &x,&y);
            printf("%lld\n", querySegment(x, y));
        }
        else if(mode==5){
            printf("%lld\n", querySegment(1, 1));
        }
    }
    return 0;
}