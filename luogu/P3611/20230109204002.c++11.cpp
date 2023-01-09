#include<stdio.h>
#include<queue>

namespace helper {
	int max(int a,int b){
		return a>b?a:b;
	}
}

const int maxn = 10000 + 7;
int n,Tmax,dances[maxn];

void input(){
	scanf("%d%d",&n,&Tmax);
	for(int i=1;i<=n;i++)
		scanf("%d",&dances[i]);
}

int getTime(int k){
	std::priority_queue<int,std::vector<int>,std::greater<int> > qu;
	for(int i=1;i<=k;i++)
		qu.push(dances[i]);
	for(int i=k+1;i<=n;i++){
//		printf("%d / %d\n",i,n);
		qu.push(qu.top()+dances[i]);
		qu.pop();
	}
	while(qu.size()!=1)qu.pop();
	return qu.top();
}

bool valid(int k){
	return getTime(k)<=Tmax;
}

void solve(){
	int l,r;
	l=1;r=n;
	
	while(l<r){
		int mid = (l+r)>>1;
//			printf("%d %d %d\n",l,r,mid);
		if(valid(mid))
			r = mid;
		else
			l = mid+1;
	}
	
	printf("%d",r);
}

int main(){
	input();
	solve();
	return 0;
}