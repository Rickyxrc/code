#include<math.h>
#include<stdio.h>
#include<algorithm>
#define maxn 100005
struct point{
	int xs,ys;
}points[maxn];
long long xlcj(point a1,point a2,point b1,point b2){return double(a2.xs-a1.xs)*double(b2.ys-b1.ys)-double(b2.xs-b1.xs)*double(a2.ys-a1.ys);}
long long dis(point a,point b){return ((a.xs-b.xs)*(a.xs-b.xs)+(a.ys-b.ys)*(a.ys-b.ys));}
int st[maxn>>1],top;
bool cmp(point x,point y){
	if(x.xs==y.xs)
		return x.ys<y.ys;
	return x.xs<y.xs;
}
long long max(int a,int b){
	return a>b?a:b;
}
long long get_longest()//求出直径 
{
       long long ans=0;
       if(top==1)
          return dis(points[0],points[1]);
       int j=2;
       for(int i=0;i<top;++i)
       {
        	while(xlcj(points[st[i]],points[st[i+1]],points[st[i+1]],points[st[j]])<xlcj(points[st[i]],points[st[i+1]],points[st[i+1]],points[st[j+1]]))
            	j=(j+1)%top;
            ans=max(ans,max(dis(points[st[i]],points[st[j]]),dis(points[st[i+1]],points[st[j]])));
       }
       return ans;      
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&points[i].xs,&points[i].ys);
	if(n<2)
		return putchar('0');
	st[0]=1;
	st[1]=2;
	top=1;
	std::sort(points+1,points+1+n,cmp);
	for(int i=3;i<=n;i++){
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
	
	printf("%lld",get_longest());
	return 0;
}