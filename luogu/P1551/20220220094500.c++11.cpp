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
int main(){
	scanf("%d%d%d",&n,&m,&p);
	init();
	for(int i=1;i<=m;i++)
		scanf("%d%d",&t1,&t2),
		merge(t1,t2);
	for(int i=1;i<=p;i++)
		scanf("%d%d",&t1,&t2),
		printf("%s\n",findf(t1)==findf(t2)?"Yes":"No");
	return 0;
}