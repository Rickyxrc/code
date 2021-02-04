#include<bits/stdc++.h>
#define mod 9901
using namespace std;
long long a,b,s=1,u;
long long func(long long aa,long long bb){
	long long n=bb/2-!(bb%2);
	long long bk=0;
	long long f=1,ans=1;
	for(int i=1;i<=n;i++)
		f*=aa,f%=mod,
		ans+=f,ans%=mod;
	if(!(bb%2))
		bk=((f*aa*f*aa)+(ans)*(1+f*aa))%mod;
	else
		bk=((ans)*(1+f*aa))%mod;
	return bk;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>a>>b;
	for(unsigned register long long i=2;(i<=a)&&(a!=1);i++,u=0){
		while(!(a%i))
			u+=b,
			a/=i;
		if(u)
			s*=func(i,u),
			s%=mod;
	}
	cout<<s;
	return 0;
}