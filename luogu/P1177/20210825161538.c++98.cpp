#include<stdio.h>
#include<stdlib.h>
int num[100005];
void swap(int& a,int& b){
	int t=a;
	a = b  ;
	b = t  ;
}
void q_sort(int l,int r){
	int middle = num[(l + r) / 2];
    int i = l,j = r;
    do {
        while (num[i] < middle) i++;
        while (num[j] > middle) j--;
        if (i <= j)
        {
            swap(num[i],num[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j) q_sort(l,j);
    if (i < r) q_sort(i,r);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	q_sort(1,n);
	for(int i=1;i<=n;i++)
		printf("%d ",num[i]);
	return 0;
}