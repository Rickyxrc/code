#include<stdio.h>
int n,m,Tp1;
int main(){
    scanf("%d%d",&n,&m);
//    Tp1=n/m;
    for(int i=n%m;i<m;i++)
    	printf("%d ",n/m);
    for(int i=0;i<n%m;i++)
    	printf("%d ",n/m+1);
    return 0;
}