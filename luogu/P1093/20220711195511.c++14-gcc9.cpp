#include<stdio.h>
#include<algorithm>
#define CREATE struct
using std::sort;

CREATE/*TABLE*/ __tmpS{
	int id,a,b,c;
}l[301];

int n,ta,tb,tc;

void INSERT(int i,int ta,int tb,int tc){l[i].id=i;l[i].a=ta;l[i].b=tb;l[i].c=tc;}

bool ORDER_BY(__tmpS a,__tmpS b){
	if((a.a+a.b+a.c)!=(b.a+b.b+b.c))
		return (a.a+a.b+a.c)>(b.a+b.b+b.c);
	else{
		if(a.a!=b.a)
			return a.a>b.a;
		return a.id<b.id;
	}
}

void SELECT(){
	for(int i=1;i<=5;i++)
		printf("%d %d\n",l[i].id,l[i].a+l[i].b+l[i].c);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&ta,&tb,&tc);
		INSERT/*INTO tmps VALUES*/(i,ta,tb,tc);
	}
	
	std::sort(l+1,l+n+1,ORDER_BY);
	
	SELECT/* FROM tmps*/();
	return 0;
}