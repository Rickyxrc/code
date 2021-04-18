#include<bits/stdc++.h>
using namespace std;
int jc[10]={1,1,2,6,24,120,720,5040,40320,362880};
int flag[10];
int main(){
	int n,Tp,solution=0,cnt;
	scanf("%d",&n);
//	getchar();
	for(int i=1;i<=n;i++){
		scanf("%1d",&Tp);
		flag[Tp]=1;
		cnt=0;
		for(int i=1;i<Tp;i++)
			cnt+=!flag[i];
//		printf("%d+%d!",cnt,jc[n-i]);
		solution+=cnt*jc[n-i]; 
	}
	printf("%d",solution+1);
	return 0;
}