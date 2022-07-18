#include<stdio.h>
//#include<iostream>
#include<algorithm>
#define maxn 1002
std::pair<int,int> p[maxn];
int n;
long long sum;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i].first);
		p[i].second=i;
	}
	std::sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		printf("%d ",p[i].second);
		sum+=p[i].first*(n-i);
	}
	printf("\n%.2f",(double)sum/n);
	return 0;
}
