#include<stdio.h>
int Tp[1010][1010],__Tp__;
int max(int x,int y){return x>y?x:y;}
int main(){
	scanf("%d",&__Tp__);
	for(int i=1;i<=__Tp__;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&Tp[i][j]);
	for(int i=__Tp__;i>=1;i--)
		for(int j=1;j<=i;j++)
			Tp[i][j] = max(Tp[i+1][j],Tp[i+1][j+1]) + Tp[i][j];
	printf("%d",Tp[1][1]);
	return 0;
}