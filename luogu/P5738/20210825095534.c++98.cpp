#include<stdio.h>
#include<bits/locale_facets.h>

int n,s,sum,maxx,minn,num;
double av,max_av=-1e7;

inline int read(){
	char ch;
	int f=0,x=1;
	while(!isdigit(ch)){ch=getchar();}
	while( isdigit(ch))f=(f<<3)+(f<<1)+(ch^48),ch=getchar();
	return f;
}

int main(){
	n=read();s=read();
	for(int i=1;i<=n;i++){
		sum=0;
		maxx=-2147483648;
		minn=2147483647;
		for(int i=1;i<=s;i++){
			num=read();
			sum+=num;
			if(maxx < num)
				maxx = num ;
			if(minn > num)
				minn = num ;
		}
			
		av = double(sum-maxx-minn) / (s-2) ;
//		printf("%lf\n",av);
		if (max_av < av)
			max_av = av;
	}
		
	printf("%.2lf",max_av);
	return 0;
} 