#include<stdio.h>
int main(){
	long long t;
	scanf("%lld",&t);
	switch(t%4){
		case 0:return!printf("%lld",t);
		case 1:return!putchar(49);
		case 2:return!printf("%lld",t^1);
		case 3:return!putchar(48);
	}
}