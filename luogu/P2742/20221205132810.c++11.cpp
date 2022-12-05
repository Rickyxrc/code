#include<stdio.h>
#include<stack>
#include<algorithm>
#include<cmath>

const int maxn = 200007;

struct Node 
{
    double x,y;
}p[maxn],s[maxn];

bool operator <(Node x,Node y){
	if(x.x == y.x)
		return x.y<y.y;
	return x.x<y.x;
}

double check(Node a1,Node a2,Node b1,Node b2)//检查叉积是否大于0，如果是a就逆时针转到b 
{
    return (a2.x-a1.x)*(b2.y-b1.y)-(b2.x-b1.x)*(a2.y-a1.y);
}

double dis(Node x,Node y){
//	printf("%lf %lf - %lf %lf\n",x.x,x.y,y.x,y.y);
	return sqrt((x.x-y.x)*(x.x-y.x) + (x.y-y.y)*(x.y-y.y));
}

int n,top,top_p,exists[maxn];

double ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	
	if(n<2)
		return !puts("0");
	
	std::sort(p+1,p+n+1);
	
	s[0] = p[1];
	s[1] = p[2];
	top=1;
	
//	for(int i=1;i<=n;i++)
//		printf("%.3lf %.3lf\n",p[i].x,p[i].y);
	
	for(int i=3;i<=n;i++){
		while(top && check(s[top-1],s[top],s[top],p[i]) <= 0)
			top--;
		s[++top] = p[i];
	}
	
//	s[++top] = p[n];
	top_p = top;
	
	for(int i=n-1;i;i--){
		while(top>top_p && check(s[top-1],s[top],s[top],p[i]) <= 0)
			top--;
		s[++top] = p[i];
	}
	
//	for(int i=0;i<top;i++){
//		printf("%lf %lf\n",s[i].x,s[i].y);
//	}
	
	for(int i=0;i<top;i++){
		ans += dis(s[i],s[i+1]);
//		printf("%lf\n",dis(s[i-1],s[i]));
	}
//	ans += dis(s[0],s[top-1]);
	
	printf("%.2lf",ans);
	return 0;
}