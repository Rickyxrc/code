#include<stdio.h>
int a,b,c,d,T,val,xq,tpp,res;
inline int min(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		res=0;xq=0;
		if(a==0){
			puts("1");
			continue;
		}
		if(c>b)
			tpp = c,
			c = b,
			b = tpp;
//		printf("<%d %d %d %d>\n",a,b,c,d);
		res += a;xq += a;
		res += c<<1;b-=c,c=0;
		if(xq > b+d)
			res += b+d;
		else
			if(xq == b+d)
				res += b+d;
			else
				res += min(xq,b+d)+1;
		printf("%d\n",res);
	}
}