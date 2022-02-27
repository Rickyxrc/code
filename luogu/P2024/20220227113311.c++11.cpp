#include<stdio.h>
#define maxn 150077
int f[maxn];
void init(int n){for(int i=1;i<=n;i++)f[i]=i;}
int ff(int x){return f[x]=(f[x]==x?x:ff(f[x]));}
void merge(int i,int j){i=ff(i);j=ff(j);f[i]=j;}
bool eq(int i,int j){return ff(i)==ff(j);}
int n,k,t1,t2,t3,ans;
int main(){
	scanf("%d%d",&n,&k);
	init(n*3+7);
	while(k--){
		scanf("%d%d%d",&t1,&t2,&t3);	
		if(t2>n||t3>n){ans++;continue;}
		if(t1==1){
			if(eq(t2+n,t3)||eq(t2+2*n,t3)){ans++;continue;}
			merge(t2,t3);
			merge(t2+n,t3+n);
			merge(t2+2*n,t3+2*n);
		}
		else{
			if(eq(t2,t3)||eq(t2+2*n,t3)){ans++;continue;}
			merge(t2,t3+2*n);
			merge(t2+n,t3);
			merge(t2+2*n,t3+n);
		}
	}
	printf("%d",ans);
	return 0;
}