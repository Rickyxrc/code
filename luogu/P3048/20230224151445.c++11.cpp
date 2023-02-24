#include<stdio.h>
#include<unordered_map>

#define maxk 13

std::unordered_map<int,int> st[maxk];


int LJ(int k,int n){
	if(k == 1)
		return 1;
	
	if(st[k][n])
		return st[k][n];
	
	int res=1;
	for(int i=1;i<=n;i++)
		res += LJ(k-1,i);
	st[k][n] = res;
	return res;
}

int nums[1000007];

void solve(int num,int k){
	if(k == 1){
		nums[num-1] = 1;
		return;
	}
	if(num == 1){
		for(int i=0;i<k;i++)nums[i]=1;
		return;
	}
	int fxid = 1;
	while(num - LJ(k,fxid) > 1)
		num -= LJ(k,fxid++);
	nums[fxid+k-1]=1;
	solve(num-1,k-1);
}

int n,k,qd0=true,idx;
int main(){
//	freopen("cowids.in" ,"r",stdin );
//	freopen("cowids.out","w",stdout);
	scanf("%d%d",&n,&k);
	solve(n,k);
	idx=999999;
	for(int i = 999999;i>=0;i--){
		if(qd0 && !nums[i])continue;
		qd0=0;putchar(48|nums[i]);
	}
	if(qd0)putchar(48);
	return 0;
} 