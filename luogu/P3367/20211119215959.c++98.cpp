#include<stdio.h>
#define maxn 10005 
struct bcj{
	int k[maxn],size;
	void init(int s){
		for(int i=1;i<=s;i++)
			k[i]=i;
	}
	int findf(int i){
		if(k[i] == i)
			return i;
		return k[i] = (findf(k[i]));
	}
	void merge(int i,int j){
		i=findf(i);
		j=findf(j);
		k[i]=k[j];
		return;
	}
	bool is(int i,int j){
		return findf(i) == findf(j);
	}
};
int n,m,tp1,tp2,tp3;
bcj k;
int main(){
	scanf("%d%d",&n,&m);
	k.init(n);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&tp1,&tp2,&tp3);
		if(tp1==1){
			k.merge(tp2,tp3);
		}
		else
			printf("%c\n",k.is(tp2,tp3)?'Y':'N');
	}
	return 0;
}