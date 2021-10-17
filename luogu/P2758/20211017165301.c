#include<stdio.h>
#include<string.h>
char st1[2020],st2[2020];
int Tp[2003][2003];
int min(int a,int b){
	return a<b?a:b;
}
int main()
{
	scanf("%s%s",st1,st2);
	for(int i=0;i<=strlen(st1);i++)Tp[0][i]=i;
	for(int i=1;i<=strlen(st2);i++)
	{
		Tp[i][0]=i;
		for(int j=1;j<=strlen(st1);j++)
			Tp[i][j]=min(min(Tp[i-1][j-1]+(st1[j-1]!=st2[i-1]),Tp[i][j-1]+1),Tp[i-1][j]+1);
	}
	printf("%d",Tp[strlen(st2)][strlen(st1)]);
	return 0;
}