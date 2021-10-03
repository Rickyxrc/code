#include<stdio.h>
char tp;
int main(){
	while(1){
		tp = getchar();
		if (tp == '\\'){
			tp = getchar();
			if(tp == 'r'){
				tp = getchar();
				tp = getchar();
				if(tp == 'n')
					puts("windows");
				else
					puts("mac");
				return 0;
			}
			if(tp == 'n'){
				puts("linux");
				return 0;
			}
		}
	}
}