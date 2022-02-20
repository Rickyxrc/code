#include<stdio.h>
#define maxn 100000
int t[maxn],n,m,t1,t2,t3;
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
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		if(t1==1)
			merge(t2,t3);
		else
			printf("%c\n",(findf(t2)==findf(t3))?'Y':'N');
	}
	return 0;
}