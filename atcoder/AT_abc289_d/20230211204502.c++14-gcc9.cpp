#include<stdio.h>
#include<queue>

std::queue<int> qu;

const int maxn = 1e5+7;

int ups[maxn],traps[maxn],book[maxn],n,m,targg,fr,tm;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",ups+i);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&tm),
		traps[tm] = 1;
	scanf("%d",&targg);
	
	qu.push(0);
	
	while(!qu.empty()){
		fr = qu.front();
//		printf("<%d>",fr);
		qu.pop();
		if(traps[fr] || book[fr] || fr > targg)
			continue;
		book[fr]=1;
		if(fr == targg)
			return puts("Yes")&0;
		
		for(int i=1;i<=n;i++)
			qu.push(fr+ups[i]);
	}
	return puts("No")&0;
}