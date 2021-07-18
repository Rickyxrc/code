#include<stdio.h>
int t,s,w;
int main(){
	scanf("%d",&t);
	w=t;
	t*=2;
	for(int i=1;i<=w;i++)
		for(int j=i+1;j<=w;j++){
			s=(i+j)*(j-i+1);
			if(s>t)break;
			if(s==t){
				printf("%d %d\n",i,j);
				break;
			}
		}
	return 0;
} 