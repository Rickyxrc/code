#include<cstdio>
#include<algorithm>
#define putnum(A) putchar(A+48)
using namespace std;
int main(){
	int k[4],T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d%d%d",&k[1],&k[2],&k[3]);
		sort(k+1,k+4);
		if(k[1]==0&&k[2]==0)
			putnum(0);
		else if(k[1]==0)
			putnum(2-(k[2]==k[3]));
		else if(k[1]==k[2]||k[2]==k[3])
			putnum(2);
		else if(k[1]!=k[2])
			if(k[1]+k[2]==k[3])
				putnum(2);
			else if(k[2]==k[3])
				putnum(2);
			else
				putnum(3);
		putchar('\n');
	}
	return 0;
} 