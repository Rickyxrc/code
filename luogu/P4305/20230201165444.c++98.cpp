#include<map>
#include<stdio.h>

std::map<int,int> mp;

int T,n,t;

int main(){
	scanf("%d",&T);
	
	while(T--){
		mp.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&t);
			if(!mp[t])
				mp[t]=1,
				printf("%d ",t);
		}
		putchar('\n');
	}
	return 0;
}