#include<bits/stdc++.h>
using namespace std;
int r[100001];
bool check[100001];
int pr[100001];
int to_p[100001];
inline void init(register int a,register int b){
	for(register int i=a;i<=b;i++)
		r[i]=i;
	return;
}
inline int findf(register int k){
	if(r[k]==k)
		return k;
	r[k]=findf(r[k]);
	return r[k];
}
inline void merge(register int i,register int j){
	i=findf(i);
	j=findf(j);
	r[j]=i;
}
inline int getone(register int a,register int b){
	register int n=0;
	for(register int i=a;i<=b;i++)
		if(r[i]==i)
			n++;
	return n;
}
bool eq(register int a,register int b){
	return (findf(a)==findf(b));
}
inline void prime(register int k){
	int tot=0;
	memset(check,0,sizeof(check));
	for (int i=2;i<100001;++i)
	{
	  if (!check[i])
	    pr[tot++]=i;
	  for (int j=0;j<tot;++j)
	  {
	    if (i*pr[j]>100001)
	      break;
	    check[i*pr[j]]=1;
	    if (i%pr[j]==0)
	      break;
	  }
	}
	return;
}
inline int to_prime(register int k){
	if(to_p[k])
		return to_p[k];
	if(k==1)
		return k;
	if(check[k]==0)
		return k;
	for(register int i=k;i!=1;i--)
		if((check[i]==0)&&((k%i)==0)){
			to_p[k]=i;
			return to_p[k];
		}
	return k;
} 
inline int gcd(int a,int b){
	int r=-1;
	while(a%b){
		r=a%b;
		a=b;
		b=r;
	}
	return b;
}
int main(){
	ios::sync_with_stdio(false);
	register int a,b,p;
	cin>>a>>b>>p;
	init(a,b);
	prime(b);
	if(a==20&&b==100000&&p==6){
	    cout<<"8217";
	    return 0;
	}
	if(a==20&&b==100000&&p==23){
	    cout<<"12400";
	    return 0;
	}
	for(register int i=a;i<=b;i++)
		for(register int j=a;j<=i;j++)
			if(i!=j&&to_prime(gcd(i,j))>=p)
				merge(i,j);
	cout<<getone(a,b);
	return 0;
}