#include<stdio.h>
#define maxn 100003
int lst[maxn],n,cnt;
void swap(int& a,int& b){
	int t=a;
	a = b  ;
	b = t  ;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",lst+i);
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i;j++){
			if(lst[j] > lst[j+1]){
			    swap(lst[j],lst[j+1]);
			    cnt++;
			}
		}
			
	printf("%d",cnt);
	return 0;
}