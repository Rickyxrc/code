#include<stdio.h>
int n,cnt1,tp,Tt;
int main(){
	scanf("%d",&Tt);
	while(Tt--){
		cnt1=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&tp),
			cnt1 += (tp==1);
		printf("%d\n",((cnt1+1)>>1)+(n-cnt1));
	}
	return 0;
} 