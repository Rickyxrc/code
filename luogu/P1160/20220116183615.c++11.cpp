#include<stdio.h>
#include<memory.h>
#include<list>
#include<algorithm>
#define maxn 300000

std::list<int> lint;
std::list<int>::iterator it;

std::list<int>::iterator smap[maxn];

int n,tp,p;

int main(){
	scanf("%d",&n);
	
		
	smap[1]=lint.insert(++lint.begin(),1);
	
	for(int i=2;i<=n;i++){
		scanf("%d%d",&tp,&p);
		it = smap[tp];
		if(p==1)
			it++;
		smap[i] = lint.insert(it,i);;
	}
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&tp);
		if(smap[tp]==lint.begin())
			continue;
		lint.erase(smap[tp]);
		smap[tp]=lint.begin();
	}
	
	for(it=lint.begin();it!=lint.end();it++)
		printf("%d ",*it);
	printf("\n");
	
	return 0;
}
