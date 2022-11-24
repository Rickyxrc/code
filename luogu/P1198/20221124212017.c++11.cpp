#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node
{
    ll l,r,sum;
}tree[800005];

ll m,d;
ll lass,lest;
void build(ll p,ll l,ll r)
{
    tree[p].l=l;tree[p].r=r;tree[p].sum=0;
    if(l==r)return ;
    build(p<<1,l,(l+r)>>1);
    build((p<<1)+1,((l+r)>>1)+1,r);
}

void modify(ll p,ll a,ll b)
{
    if(tree[p].l>a||tree[p].r<a)return;
    if(tree[p].l==a&&tree[p].r==a)
    {
        tree[p].sum+=b;
        return;
    }
    modify(p<<1,a,b);
    modify((p<<1)+1,a,b);
    tree[p].sum=max(tree[p<<1].sum,tree[(p<<1)+1].sum);
}

ll query(ll p,ll l,ll r)
{
    if(tree[p].l>r||tree[p].r<l)return 0;
    if(tree[p].l>=l&&tree[p].r<=r)
        return tree[p].sum;
    return max(query(p<<1,l,r),query((p<<1)+1,l,r));
}
int main()
{
    ll k,b;
    int num=0;
    char a;
    scanf("%lld%lld",&m,&d);
    build(1,0,200003);
    while(m--)
    {
    	do{
    		a=getchar();
    	}while(a!='A' && a!='Q');
        scanf("%lld",&b);
        if(a=='A')
        {
            b=(b+lest)%d;
			modify(1,++lass,b);
        }
        else
        {
            lest=query(1,lass-b+1,lass);
            printf("%lld\n",lest);
        }
    }
}