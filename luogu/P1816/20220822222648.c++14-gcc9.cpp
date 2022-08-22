#include <stdio.h>
#define maxn 800005
int data[maxn], lazy[maxn], t[maxn / 4];
int n, m, size;
inline int __lc(int i) { return i << 1; }
inline int __rc(int i) { return __lc(i) | 1; }
inline int __maxValue(int a, int b) { return a < b ? a : b; }
void updateNode(int __index)
{
    data[__index] = __maxValue(data[__lc(__index)], data[__rc(__index)]);
}
void initSegmentTree(int left, int right, int *initialData, int __index = 1)
{
    if (right == -114)
        right = n - 1;
    if (left == right)
    {
        data[__index] = initialData[left];
        size = __index > size ? __index : size;
        return;
    }
    int mid = (left + right) >> 1;
    initSegmentTree(left, mid, initialData, __lc(__index));
    initSegmentTree(mid + 1, right, initialData, __rc(__index));
    updateNode(__index);
}

void updateSegment(int left, int value, int __l = 1, int __r = -114, int __index = 1)
{
    if (__r == -114)
        __r = n;
    if (__r < left || __l > left)
        return;
    if (__l == __r && __l == left)
    {
        data[__index] = __maxValue(value, data[__index]);
        return;
    }
    int mid = (__l + __r) >> 1;
    updateSegment(left, value, __l, mid, __lc(__index));
    updateSegment(left, value, mid + 1, __r, __rc(__index));
    updateNode(__index);
}
int querySegment(int left, int right, int __l = 1, int __r = -114, int __index = 1)
{
    if (__r == -114)
        __r = n;
    if (__r < left || __l > right)
        return 1<<31-1;
    if (left <= __l && __r <= right)
        return data[__index];
    int mid = (__l + __r) >> 1;
    int sum = 1<<31-1;
    sum = __maxValue(sum, querySegment(left, right, __l, mid, __lc(__index)));
    sum = __maxValue(sum, querySegment(left, right, mid + 1, __r, __rc(__index)));
    return sum;
}
int mode, x, y, k;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", t + i);
    initSegmentTree(1, n, t);
    for (int i = 1; i <= m; i++)
    {

        scanf("%d%d", &x, &y);
        printf("%d ", querySegment(x, y));
    }
    return 0;
}