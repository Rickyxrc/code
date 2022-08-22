#include<stdio.h>
#define maxn 500005

void swap(int& i,int& j){
	int t = i;
	i=j,j=t;
	return;
}

int list[maxn] = {1,3,2,6,4,7,8,5,9,10},t[maxn],n;
unsigned long long ans;

void mergeSort(int l,int r){
	if(l==r)
		return;
	int mid = (l+r)>>1;
	mergeSort(l,mid);
	mergeSort(mid+1,r);
	int i=l,j=mid+1,p=l;
	while(i<=mid && j<=r){
		if( list[i] > list[j] )
			t[p++]=list[j++],ans+=mid-i+1;
		else
			t[p++]=list[i++];
	}
	while(i<=mid)
		t[p++]=list[i++];
	while(j<=r)
		t[p++]=list[j++];
	
	for(int tmp=l;tmp<=r;tmp++)
		list[tmp] = t[tmp];
	return;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",list+i);
	mergeSort(1,n);
	printf("%lld",ans);
	return 0;
}