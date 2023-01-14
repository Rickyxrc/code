#include<stdio.h>

namespace exgcd{
	int x,y,k;
	void solve(int a,int b){
//		printf("exgcd %d %d\n",a,b);
		if(b==0){
			x=1;
			y=0;
			return;
		}
		solve(b,a%b);
		k=x;
		x=y;
		y=k-a/b*y;
		return;
	}
}

namespace solution{
	using namespace exgcd;
	int a,b;
	void input(){
		scanf("%d%d",&a,&b);
	}
	void main(){
		solve(a,b);
		printf("%d",(x+b)%b);
	}
}

int main(){
	solution::input();
	solution::main();
	return 0;
}