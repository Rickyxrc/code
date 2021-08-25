#include<stdio.h>
int k;
int monkey(int n,int ini){
	if(n==1)
		return ini;
	// ini / 2 - 1 
	return monkey(n-1,(ini+1)<<1);
}
int main(){
	int k;
	scanf("%d",&k);
	printf("%d",monkey(k,1));
	return 0;
} 