#include<stdio.h>
#define maxn 10005
int k[maxn];
void init(int n){
	for(int i=1;i<=n;i++)
		k[i] = i;
}
int getf(int n){
	return k[n] = (k[n] == n ? k[n] : getf(k[n]));
}
void merge(int i,int j){
	i = getf(i);
	j = getf(j);
	k[i] = j;
}
bool equal(int i,int j){
	return getf(i) == getf(j);
}
int main(){
	int n,m,t,t2,t3;
	scanf("%d%d",&n,&m);
	init(n);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&t,&t2,&t3);
		if(t == 1)
			merge(t2,t3);
		else
			putchar(equal(t2,t3)?'Y':'N'),
			putchar('\n');
	}
	return 0;
}