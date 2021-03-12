#include<bits/stdc++.h>
using namespace std;
struct pos{
	int a[4];
}p[100000001];
inline bool cmp(const pos& i,const pos& j){
	return i.a[0]<j.a[0];
}
double x,y,x_,y_,z,w,ans=2e9+0.01,tp,tp_,Tp,Tp_,dgr;
int n;
int main(){
	scanf("%d",&n);
	z=sin(1),w=cos(1);
	for(register int i=1;i<=n;i++){
		scanf("%lf%lf",&x,&y);
		x_=x*w-y*z;
		y_=x*z+y*w;
		p[i].a[0]=x_;
		p[i].a[1]=y_;
		p[i].a[2]=x;
		p[i].a[3]=y;
	}
	sort(p+1,p+1+n,cmp);
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=n;j++){
			tp=p[i].a[2];
			tp_=p[i].a[3];
			Tp=p[i+j].a[2];
			Tp_=p[i+j].a[3];
			dgr=sqrt((tp-Tp)*(tp-Tp)+(tp_-Tp_)*(tp_-Tp_));
			ans=min(dgr,ans);
		}
	}
	printf("%.4f",ans);
	return 0;
}