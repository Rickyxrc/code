#include<stdio.h>
#define maxn 30005
int sn[maxn],hn[maxn],cn[maxn];
int ff(int x){
	int sx = sn[x];
//	printf("[%d,%d]",x,sx);
	if(sx!=x){
		sn[x] = ff(sx);
		hn[x] += hn[sx];
	}
	return sn[x];
}
void merge(int i,int j){
	i = ff(i);
	j = ff(j);
	if(i!=j){
		sn[i] = j;
		hn[i] = cn[j];
		cn[j] += cn[i];
	}
}
int p,t1,t2;
char t;
int main(){
	for(int i=1;i<=30005;i++)
		sn[i] = i,hn[i] = 0,cn[i] = 1;
	scanf("%d",&p);
	while(p--){
		t=' ';
		while(t==' ' || t=='\n' || t=='\r')
			scanf("%c",&t);
		if(t=='M'){
			scanf("%d%d",&t1,&t2);
			merge(t1,t2);
		}
		else{
			scanf("%d",&t1);
			ff(t1);
			printf("%d\n",hn[t1]);
		}
	}
	return 0;
} 