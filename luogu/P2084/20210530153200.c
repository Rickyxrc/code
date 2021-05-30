#include<stdio.h>
#include<string.h>

char s[1001];
int base,poww,first=1;
int main(){
    scanf("%d",&base);
    scanf("%s",s);
    poww=strlen(s)-1;
    for(int i=0;i<strlen(s);i++){
        if(s[i]>48){
        	if(!first)putchar('+');
        	if(first)first=0;
            putchar(s[i]);
            putchar('*');
            putchar(base+'0');
            putchar('^');
            printf("%d",poww);
        }
        poww--;
    }
    return 0;
}