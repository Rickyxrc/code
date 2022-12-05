#include<math.h>
#include<stdio.h>
#include<algorithm>
#define maxn 100005
struct point{
	double xs,ys;
}points[maxn];
double xlcj(point a1,point a2,point b1,point b2){return double(a2.xs-a1.xs)*double(b2.ys-b1.ys)-double(b2.xs-b1.xs)*double(a2.ys-a1.ys);}
double dis(point a,point b){return sqrt((a.xs-b.xs)*(a.xs-b.xs)+(a.ys-b.ys)*(a.ys-b.ys));}
int st[maxn>>1],top;
double ans=0.0;
bool cmp(point x,point y){
	if(x.xs==y.xs)
		return x.ys<y.ys;
	return x.xs<y.xs;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&points[i].xs,&points[i].ys);
	if(n<2)
		return putchar('0');
	st[0]=1;
	st[1]=2;
	top=1;
	std::sort(points+1,points+1+n,cmp);
	for(int i=3;i<=n;i++){;
		while(top && xlcj(points[st[top-1]],points[st[top]],points[st[top]],points[i])<=0)
			top--;
		st[++top]=i;
	}
	int tp=top; 
	for(int i=n-1;i>=1;i--){
		while(top>tp && xlcj(points[st[top-1]],points[st[top]],points[st[top]],points[i])<=0)
			top--;
		st[++top]=i;
	}
	
	for(int i=0;i<top;i++)
//		printf("%lf,%lf -> %lf,%lf         %d -> %d\n",points[st[i]].xs,points[st[i]].ys,points[st[i+1]].xs,points[st[i+1]].ys,st[i],st[i+1]),
		ans+=dis(points[st[i]],points[st[i+1]]);
	printf("%.2lf",ans);
	return 0;
}
/*
6
0 8
0 9 
0 -2
0 0 
0 6
0 3


should : 11
*/