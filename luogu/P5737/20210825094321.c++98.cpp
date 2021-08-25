#include<stdio.h>
int isyear(int n){
	if(n%400==0)
		return 1;
	if(n%100==0)
		return 0;
	if(n%4==0)
		return 1;
	return 0;
}
int main(){
	int a,b,cnt=0;
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++)
		if(isyear(i))
			cnt++;
	printf("%d\n",cnt);
	for(int i=a;i<=b;i++)
		if(isyear(i))
			printf("%d ",i);
	return 0;
} 