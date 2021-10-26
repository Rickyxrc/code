#include<stdio.h>
int n,L,R,max;
int maxx(const int& a,const int& b){return a>b?a:b;}
int main(){
// 	freopen("candy.in","r",stdin);
// 	freopen("candy.out","w",stdout);
	scanf("%d%d%d",&n,&L,&R);
	for(int i=L;i<=R;i++){
		max = maxx(max,i%n);
	}
	printf("%d",max);
// 	fclose(stdin);
// 	fclose(stdout);
	return 0;
}