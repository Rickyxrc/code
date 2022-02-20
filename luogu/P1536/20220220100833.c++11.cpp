#include<stdio.h>
#define maxn 5005
int t[maxn],n,m,p,t1,t2,t3;
void init(){
	for(int i=1;i<=n;i++)
		t[i]=i;
}
inline int findf(int n){return t[n]=((t[n]==n)?n:findf(t[n]));}
void merge(int i,int j){
	i=findf(i);
	j=findf(j);
	t[i]=j;
}
int finds(){
	int s=0;
	for(int i=1;i<=n;i++)
		if(t[i]==i)
			s++;
	return s;
}
int T;
int main(){
	while(1){
		scanf("%d",&n);
		if(!n)
			return 0;
		scanf("%d",&m);
		init();
		for(int i=1;i<=m;i++)
			scanf("%d%d",&t1,&t2),
			merge(t1,t2);
		printf("%d\n",finds()-1);
	}
	
	return 0;
}