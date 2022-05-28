#include <bits/stdc++.h>
#define N 100007
int n,m,cnt[N],lowidx[N],inde,res;
bool vised[N],flag[N];
std::vector<int> edge[N];
void func(int u,int fath){
	    vised[u]=true;
	    lowidx[u]=cnt[u]=++inde;
	    int child=0;
	    for(auto v:edge[u]){
	    if(!vised[v]){
	        child++;
	        func(v,u);
	        lowidx[u]=std::min(lowidx[u],lowidx[v]);
	        if(fath!=u&&lowidx[v]>=cnt[u]&&!flag[u])
	            flag[u]=true,
	            res++;
	    }else
	        if(v!=fath)
	            lowidx[u]=std::min(lowidx[u],cnt[v]);
	}
	if (fath==u&&child>=2&&!flag[u]){
	    flag[u]=true,
	    res++;
	}
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if(!vised[i]){
            inde=0;
            func(i,i);
        }
    printf("%d\n",res);
    for (int i=1;i<=n;i++)
        if (flag[i])
            printf("%d ",i);
    return 0;
}