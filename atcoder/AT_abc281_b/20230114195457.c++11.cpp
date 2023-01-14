#include<stdio.h>
#include<ctype.h>
#include<string.h>

char s[20];

int main(){
	scanf("%s",s);
	if(strlen(s) != 8)
		return 0&puts("No");
	
	if(s[0]<'A' || s[0]>'Z' || s[7]<'A' || s[7]>'Z')
		return 0&puts("No");
	
	for(int i=1;i<=6;i++)
		if(!isdigit(s[i]))
			return 0&puts("No");
	
	if(s[1] == '0')
		return 0&puts("No");
	
	return 0&puts("Yes");
}