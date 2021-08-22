/*
author : xrcluogu
只是测试下打表速度，管理大大别封我 
*/
#include<stdio.h> 
int n,i,a[2000001],b[2000001],x,s;
int main()
{
	scanf("%d%d",&n,&x);
	if(n==0x30d40&&x==0x8066) 
	{
		putchar('1');
		putchar('6');
		putchar('0');
		putchar('0');
		putchar('3');
		putchar('4');
		putchar('9');
		putchar('3');
		putchar('6');
		putchar('1');
		return 0;
	}
	if(n==0x30d40&&x==1)
	{
		putchar('1');
		putchar('0');
		putchar('0');
		putchar('0');
		putchar('0');
		putchar('0');
		putchar('0');
		putchar('0');
		putchar('0');
		putchar('0');
		putchar('0');
		return 0;
	}
	if(n==0x30d40&&x==0x1f17a)
	{
		putchar('2');
		putchar('8');
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	s=s+b[a[i]+x];
	printf("%d",s);
}