#include<stdio.h>
#define ll long long
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x = 1, y = 0;
        return a;
    }
    ll gcd = exgcd(b, a % b, x, y), t = x;
    x = y;
    y = t - a / b * y;
    return gcd;
}
ll n, m, x, y, b, x0, y0;
int main(){
    scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &b);
    ll a = n - m, c = x - y;
    if(a<0)
        c = -c, a = -a;
    ll ans = exgcd(a, b, x0, y0);
    if(c%ans!=0)
        return !puts("Impossible");
    else{
        c /= ans, b /= ans;
        printf("%lld", (x0 * (c) % b + b) % b);
    }
    return 0;
}