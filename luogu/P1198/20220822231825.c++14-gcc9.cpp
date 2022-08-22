#include <stdio.h>
#define maxn 800005
long long data[maxn];
long long n, m, size;
inline long long __lc(long long i) { return i << 1; }
inline long long __rc(long long i) { return __lc(i) | 1; }
inline long long __maxValue(long long a, long long b) { return a > b ? a : b; }
void updateNode(long long __index)
{
    data[__index] = __maxValue(data[__lc(__index)], data[__rc(__index)]);
}

void updateSegment(long long left, long long value, long long __l = 1, long long __r = -114, long long __index = 1)
{
    if (__r == -114)
        __r = 200000;
    if (__r < left || __l > left)
        return;
    if (__l == __r && __l == left)
    {
        data[__index] = value;
        return;
    }
    long long mid = (__l + __r) >> 1;
    updateSegment(left, value, __l, mid, __lc(__index));
    updateSegment(left, value, mid + 1, __r, __rc(__index));
    updateNode(__index);
}
long long querySegment(long long left, long long right, long long __l = 1, long long __r = -114, long long __index = 1)
{
    if (__r == -114)
        __r = 200000;
    if (__r < left || __l > right)
        return 0;
    if (left <= __l && __r <= right)
        return data[__index];
    long long mid = (__l + __r) >> 1;
    long long sum = 0;
    sum = __maxValue(sum, querySegment(left, right, __l, mid, __lc(__index)));
    sum = __maxValue(sum, querySegment(left, right, mid + 1, __r, __rc(__index)));
    return sum;
}
long long mode, x, y, k, last, lenn, nn;
int main()
{
    scanf("%lld%lld", &nn, &m);
    size = 800007;
    for (long long i = 1; i <= nn; i++)
    {
        mode = 0;
        while (mode != 'A' && mode != 'Q')
            mode = getchar();
        if (mode == 'A')
        {
            scanf("%lld", &x);
            updateSegment(++lenn, (x + last) % m);
        }
        else
        {
            scanf("%lld", &x);
            last = querySegment(lenn - x + 1, lenn);
            printf("%lld\n", last);
        }
    }
    return 0;
}