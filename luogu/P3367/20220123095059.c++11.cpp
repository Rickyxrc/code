#include<stdio.h>
#define maxn 100000
int k[maxn];
int findf(int ki){return k[ki]=(k[ki]==ki?k[ki]:findf(k[ki]));}
void init(int n){
	for(int i=1;i<=n;i++)
		k[i]=i;
}
void merge(int i,int j){
	i = findf(i);
	j = findf(j);
	if(i!=j)
		k[j] = i;
	return;
}
int query(int i,int j){return (findf(i)==findf(j));}
int main(){
	int n,m,tp,tp2,tp3;
	scanf("%d%d",&n,&m);
	init(n);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&tp,&tp2,&tp3);
		if(tp==1)
			merge(tp2,tp3);
		else
			putchar(query(tp2,tp3)?'Y':'N'),putchar('\n');
	}
	return 0;
}