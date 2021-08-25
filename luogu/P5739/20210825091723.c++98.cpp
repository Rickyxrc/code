#include<stdio.h>
int dg(int n){
	if (n==0)
		return 1;
	return dg(n-1)*n;
}
int main(){
	int k;
	scanf("%d",&k);
	printf("%d",dg(k));
	return 0;
} 