#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	if (n%400)
		if( n%100 )
			if( n%4 == 0 )
				putchar('1');
			else
				putchar('0');
		else
			putchar('0');
	else
		putchar('1');
	return 0;
} 