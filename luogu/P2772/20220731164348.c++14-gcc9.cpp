#include<algorithm>
#include<stdio.h>
#include<vector>
std::vector<std::pair<int,int> >nodes;
int n,tx,ty,first,mxx=2>>31;
bool cmp(std::pair<int,int>x,std::pair<int,int>y){
	if(x.second!=y.second)
		return x.second>y.second;
	return x.first>y.first;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&tx,&ty),
		nodes.push_back({tx,ty});

	sort(nodes.begin(),nodes.end(),cmp);
	
	for(auto t:nodes){
		if(t.first>mxx){
			if(first)putchar(',');
			else first=1;
			printf("(%d,%d)",t.first,t.second);
			mxx = t.first;
		}
	}	
	return 0;
}