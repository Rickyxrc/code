#include <stdio.h>
#define ll long long
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll gcd = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - a / b * y;
    return gcd;
}
ll fastmul(ll a, ll b, ll n)
{
    ll r = 0;
    while (b)
    {
        if (b & 1)
            r = (r + a) % n;
        a = (a + a) % n;
        b >>= 1;
    }
    return r;
}
ll china(ll C[], ll M[], ll k)
{
    ll x, y, ans = 0, m, n = 1;
    for (ll i = 0; i < k; i++)
        n *= M[i];
    for (ll i = 0; i < k; i++)
    {
        m = n / M[i];
        exgcd(M[i], m, x, y);
        y = (y % M[i] + M[i]) % M[i];
        C[i] = (C[i] % M[i] + M[i]) % M[i];
        ans = (ans + fastmul(y * m, C[i], n)) % n;
        }
    if (ans >= 0)
        return ans;
    else
        return ans + n;
}
int main()
{
    ll k, i, C[15], M[15];
    scanf("%lld", &k);
    for (i = 0; i < k; i++)
        scanf("%lld", &C[i]);
    for (i = 0; i < k; i++)
        scanf("%lld", &M[i]);
    printf("%lld", china(C, M, k));
}