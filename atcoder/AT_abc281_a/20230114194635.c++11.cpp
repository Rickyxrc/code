#include<stdio.h>
int n;
int main(){
	scanf("%d",&n);
	for(int i=n;i>=0;i--)
		printf("%d",i),putchar('\n');
	return 0;
} 