#include<stdio.h>
int main(){
	register int cnt=0;
	for(int i=1;i<=8;i++){
		cnt+=getchar()-48;
	}
	putchar(cnt+48);
	return 0;
}