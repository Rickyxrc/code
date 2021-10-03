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
					printf("windows");
				else
					printf("mac");
				return 0;
			}
			if(tp == 'n'){
				printf("linux");
				return 0;
			}
		}
	}
}