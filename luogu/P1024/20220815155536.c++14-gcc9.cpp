#include<stdio.h>
#include<math.h>
double t;
double a,b,c,d;
double func(double x){
	return x*x*x*a+x*x*b+x*c+d;
}
int main(){
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	for(double t=-100.00;(t-100.00)<1e-5;t+=0.01)
		if(fabs(func(t)-0)<1e-6)
			 printf("%.2lf ",t);
}