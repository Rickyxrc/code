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
		case 1:
			printf("%d",days[1]);
			break;
		case 3:
			printf("%d",days[3]);
			break;
		case 4:
			printf("%d",days[4]);
			break;
		case 5:
			printf("%d",days[5]);
			break;
		case 6:
			printf("%d",days[6]);
			break;
		case 7:
			printf("%d",days[7]);
			break;
		case 8:
			printf("%d",days[8]);
			break;
		case 9:
			printf("%d",days[9]);
			break;
		case 10:
			printf("%d",days[10]);
			break;
		case 11:
			printf("%d",days[11]);
			break;
		case 12:
			printf("%d",days[12]);
			break;
		case 2:
			days[2]+=rn(y);
		default:
			printf("%d",days[n]);
	}
	return 0;
} 