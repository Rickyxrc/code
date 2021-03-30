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
int stk[maxn],visit[maxn],cnt,tot,ind,ans,cntt;
int flg[maxn];
bool need[maxn];

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
		cntt++;
        do{
//            printf("%d ",stk[ind]);
            visit[stk[ind]]=0;
            flg[stk[ind]]=cntt;
            ind--;
        }while(x!=stk[ind+1]);
//        printf("\n");
    }
    return;
}
int main()
{
    int n=read(),m=read();
    int x,y;
    for(int i=1;i<=m;i++){
    	x=read(),
        y=read();
        if(x!=y)
        	add(x,y);
	}
	
    for(int i=1;i<=n;i++)
        if(!DFN[i])tarjan(i);
    
//    memset(need,1,sizeof(bool)*(n+1));
    for(int i=1;i<=n;i++)
    	for(vector<int>::iterator it=edge[i].begin();it<edge[i].end();it++){
    		int Tp=*it;
    		if(flg[i]!=flg[Tp]){
    			need[flg[Tp]]=1;
			}
		}
	
	for(int i=1;i<=cntt;i++)
		ans+=!need[i];
	
	write(ans);
	return 0;
}