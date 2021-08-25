#include<stdio.h>
int num[200005],cnt=0,now=0;
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
	now=num[1];
	for(int i=1;i<=n;i++){
//		printf("::%d\n",num[i]);
		if(now!=num[i])
			printf("%d %d\n",num[i-1],cnt),now=num[i],cnt=1;
		else
			cnt++;
	}
	printf("%d %d\n",num[n],cnt);
	return 0;
}