#include<math.h>
#include<stdio.h>
#include<algorithm>
#define maxn 50000
const double pi = 3.14159265358979323846264338327950288;
struct point{
	double xs,ys;
}points[maxn];
int pointcnt=0;
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
	double a,b,r,x,y,theta;
	scanf("%d%lf%lf%lf",&n,&a,&b,&r);
	a-=2*r;
	b-=2*r;
	double l=sqrt(a*a+b*b)/2;
	double phi = atan(a/b);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&x,&y,&theta);
		double dx=cos(theta+phi)*l;
		double dy=sin(theta+phi)*l;
		points[++pointcnt] = {x+dx,y+dy};
		points[++pointcnt] = {x-dx,y-dy};
		dx=cos(theta-phi)*l;
		dy=sin(theta-phi)*l;
		points[++pointcnt] = {x+dx,y+dy};
		points[++pointcnt] = {x-dx,y-dy};
	}
	st[0]=1;
	st[1]=2;
	top=1;
	std::sort(points+1,points+1+pointcnt,cmp);
	for(int i=3;i<=pointcnt;i++){;
		while(top && xlcj(points[st[top-1]],points[st[top]],points[st[top]],points[i])<=0)
			top--;
		st[++top]=i;
	}
	int tp=top; 
	for(int i=pointcnt-1;i>=1;i--){
		while(top>tp && xlcj(points[st[top-1]],points[st[top]],points[st[top]],points[i])<=0)
			top--;
		st[++top]=i;
	}
	
	for(int i=0;i<top;i++)
		ans+=dis(points[st[i]],points[st[i+1]]);
	
	printf("%.2lf",ans+2*pi*r);
	return 0;
}