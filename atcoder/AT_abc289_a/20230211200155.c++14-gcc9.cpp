#include<stdio.h>
#include<string.h>
#define maxn 17
char s[maxn];
int slen;
int main(){
	scanf("%s",s);
	slen = strlen(s);
	for(int i=0;i<slen;i++)
		putchar(s[i]^1);
	return 0;
} 