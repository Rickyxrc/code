#include<stdio.h>
int res;
char ch;
int main(){
	do{
		ch = getchar();
		if(ch!='w' && ch!='v')break;
		res += 1+(ch=='w');
	}while(true);
	printf("%d",res);
	return 0;
} 