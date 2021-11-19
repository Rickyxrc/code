#include<stdio.h>
int T,n,k,tp;
int main(){
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		k=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&tp),
			k^=tp;
		if(k!=0)
			printf("Yes\n");
		else
			printf("No\n");
	}
    return 0;
}