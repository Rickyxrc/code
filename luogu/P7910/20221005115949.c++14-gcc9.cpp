#include<stdio.h>
#define maxn 8889
//#define DEBUG
long long mapp[maxn],arr[maxn],poss[maxn],n,q,tnum,mode,t1,t2;
void swap(long long &a,long long &b){
	long long t=a;
	a=b;
	b=t;
}
void swapE(long long a,long long b){
	swap(mapp[a],mapp[b]);
	swap(arr[a],arr[b]);
	return;
}
int main(){
	scanf("%lld%lld",&n,&q);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&tnum);
		mapp[i]=i;
		arr[i]=tnum;
	}
	
	for (long long i = 1; i <= n; i++)
		for (long long j = i; j >= 2; j--)
			if(arr[j-1] == arr[j]&&mapp[j-1] > mapp[j])
				swapE(j-1,j);
			else if (arr[j] < arr[j-1])
				swapE(j-1,j);
//	
//	for(long longi=1;i<=n;i++)
//		for(long longj=i+1;j<=n;j++){
//			if(arr[j-1]>arr[j]){
//				swapE(j-1,j);
//			}
//		}
	
	for(long long j=1;j<=n;j++)
		poss[mapp[j]] = j;
	
	for(long long i=1;i<=q;i++){
		scanf("%lld",&mode);
		if(mode==2){
			scanf("%lld",&t1);
			printf("%lld\n",poss[t1]);
		}
		else if(mode==1){
			scanf("%lld%lld",&t1,&t2);
			arr[poss[t1]]=t2;
			
			for(long long j=2;j<=n;j++)
				if(arr[j-1] == arr[j]&&mapp[j-1] > mapp[j])
						swapE(j-1,j);
				else if(arr[j-1]>arr[j]){
					swapE(j-1,j);
				}
			for(long long j=n;j>1;j--)
				if(arr[j-1] == arr[j]&&mapp[j-1] > mapp[j])
						swapE(j-1,j);
				else if(arr[j-1]>arr[j]){
					swapE(j-1,j);
				}
			for(long long j=1;j<=n;j++)
				poss[mapp[j]] = j;
				
//			for (long longj = n; j >= 2; j--)
//				if (arr[j] < arr[j-1]) {
//					swapE(j-1,j);			
//				}
//			for (long longj = 2; j <= n; j++)
//				if (arr[j] < arr[j-1]) {
//					swapE(j-1,j);			
//				}
			
//			#ifdef DEBUG
//			for(long long i=1;i<=n;i++){
//				printf("[%lld]",arr[i]);
//			}
//			printf("\n");
//			for(long long i=1;i<=n;i++){
//				printf("[%lld]",mapp[i]);
//			}
//			printf("\n");
//			#endif
		}
	}
	return 0;
}
/*
8 10
204242068 204242068 73216597 862314366 991541492 576986054 388949725 404262124
2 4
2 2
1 2 204242068
2 4
2 1
2 5
2 8
2 2
1 1 204242068
2 4


*/
/*
10 9
925482250 150260412 883341961 150260412 280980536 949990458 991541492 246162121 891601996 42637375
1 8 42637375
1 8 204242068
1 3 797929861
1 2 280980536
2 9
2 9
1 10 891601996
2 6
1 2 862314366

*/