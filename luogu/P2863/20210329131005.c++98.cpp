#include<bits/stdc++.h>
using namespace std;

inline int read(){
	char ch;
	int f=0;
	while(!isdigit(ch)){ch=getchar();}
	while( isdigit(ch))f=(f<<3)+(f<<1)+(ch^48),ch=getchar();
	return f;
}
static char st[30];
inline void write(int x){
	if(x==0){
		putchar('0');
		return;
	}
	register int top=0;
	while(x)
		st[top++]=x%10,
		x/=10;
	while(top)
		putchar(st[--top]+48);
	return;
}

#define maxn 100001
vector<int>edge [maxn];
int DFN[maxn],LOW[maxn];
int stk[maxn],visit[maxn],tot,ind,ans,cnt;

inline void add(int x,int y){edge[x].push_back(y);}

void tarjan(int x)
{
    DFN[x]=LOW[x]=++tot;
    stk[++ind]=x;
    visit[x]=1;
    for(vector<int>::iterator i=edge[x].begin();i<edge[x].end();i++)
    {
        if(!DFN[*i]){
            tarjan(*i);
            LOW[x]=min(LOW[x],LOW[*i]);
        }
        else if(visit[*i]){
            LOW[x]=min(LOW[x],DFN[*i]);
        }
    }
    if(LOW[x]==DFN[x])
    {
        cnt=0;
        do{
            //printf("%d ",stk[ind]);
            visit[stk[ind]]=0;
            ind--;
            cnt++;
        }while(x!=stk[ind+1]);
        if(cnt>1)
            ans++;
        //printf("\n");
    }
    return;
}

int main()
{
    int n=read(),m=read();
    int x,y;
    for(int i=1;i<=m;i++)
        x=read(),
        y=read(),
        add(x,y);
    for(int i=1;i<=n;i++)
        if(!DFN[i])tarjan(i);
    write(ans);
   return 0;
}