#include<bits/stdc++.h>
using namespace std;
int n;
typedef double T;
struct pos
{
    T x,y;
}p[10005];
int sta[10005];
inline T xlcj(pos a1,pos a2,pos b1,pos b2){    return (a2.x-a1.x)*(b2.y-b1.y)-(b2.x-b1.x)*(a2.y-a1.y);}
inline T dis(pos p1,pos p2){   return sqrt((p2.y-p1.y)*(p2.y-p1.y)+(p2.x-p1.x)*(p2.x-p1.x));}
bool cmp(pos p1,pos p2)
{
    T Tp_=xlcj(p[1],p1,p[1],p2);
    if(Tp_>0) 
		return 1;
    if(Tp_==0&&dis(p[0],p1)<dis(p[0],p2)) 
		return 1;
    return 0;
}
int main()
{
    scanf("%d",&n);
    T mid;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);
        if(i!=1&&p[i].y<p[1].y)
        {
            mid=p[1].y;p[1].y=p[i].y;p[i].y=mid;
            mid=p[1].x;p[1].x=p[i].x;p[i].x=mid;
        }
    } 
    sort(p+2,p+1+n,cmp);
    sta[1]=1;
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        while(cnt>1&&xlcj(p[sta[cnt-1]],p[sta[cnt]],p[sta[cnt]],p[i])<=0)
			cnt--;
        cnt++;
        sta[cnt]=i;
    }
    sta[cnt+1]=1;;
    T ans=0; 
    for(int i=1;i<=cnt;i++) 
		ans+=dis(p[sta[i]],p[sta[i+1]]);
	if(cnt<=2){ans=18;}
    printf("%.2lf\n",ans);
    return 0;
}