#include<stdio.h>
#include<stdlib.h>
long long Tp[31][31],bj[31][31],n,m,nn,mm,
	fxx[8] = { 1, 1,-1,-1, 2, 2,-2,-2},
	fxy[8] = { 2,-2, 2,-2, 1,-1, 1,-1};
int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&nn,&mm);
	
	for(int i=0;i<8;i++)
		bj[nn+fxx[i]][mm+fxy[i]] = 1;
	bj[nn][mm] = 1;
	
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=m;j++)
//			printf("%d ",bj[i][j]);
//		printf("\n");
//	}
	
	for(int i = 0;i<=n;i++){
		if(bj[i][0])
			break;
		Tp[i][0] = 1;
	}
	for(int i = 0;i<=m;i++){
		if(bj[0][i])
			break;
		Tp[0][i] = 1;
	}
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(bj[i][j])
				continue;
			Tp[i][j] = Tp[i][j-1] + Tp[i-1][j];
			
//			system("cls");
//			for(int i=0;i<=n;i++){
//				for(int j=0;j<=m;j++)
//					printf("%d ",Tp[i][j]);
//				printf("\n");
//			}
//			system("pause");
					
		}	
	printf("%lld",Tp[n][m]);
	return 0;
}