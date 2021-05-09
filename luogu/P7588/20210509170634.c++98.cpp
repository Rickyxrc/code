#include<bits/stdc++.h>
#define maxn 100000005
using namespace std;

int prime[maxn],cnt,n,T,mxn,Tp,Tp_,ans;
char check[maxn];
void ola_prime(){
	check[1]=1;
	for(int i=2;i<=maxn;i++){
		if(!check[i])
			prime[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(i*prime[j]>maxn)break;
			check[i*prime[j]]=1;
			if(!(i%prime[j]))break;
		}
	}
	return;
}
inline int summ(const int& x){
	if(!x)
		return 0;
	int k=x,s=0;
	while(k)
		s+=k%10,k/=10;
	return s;
}

int main(){
	scanf("%d",&T);
	ola_prime();
	for(int i=1;i<=T;i++){
		ans=0;
		scanf("%d%d",&Tp,&Tp_);
		for(int i=Tp;i<=Tp_;i++){
			if((!check[i])&&(!check[summ(i)]))
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}