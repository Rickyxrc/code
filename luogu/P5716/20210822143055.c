#include<stdio.h>
int rn(int n){
	if (n%400)
		if( n%100 )
			if( n%4 == 0 )
				return 1;
			else
				return 0;
		else
			return 0;
	else
		return 1;
}
int main(){
	int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int y,n;
	scanf("%d%d",&y,&n);
	switch(n){
		case 2:
			days[2]+=rn(y);
		default:
			printf("%d",days[n]);
	}
	return 0;
} 