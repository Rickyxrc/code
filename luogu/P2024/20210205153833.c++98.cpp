#include<bits/stdc++.h>
using namespace std;
int r[1000001];
inline void init(int n){
	for(int i=1;i<=n;i++)
		r[i]=i;
	return;
}
inline int findf(int k){
	if(r[k]==k)
		return k;
	r[k]=findf(r[k]);
	return r[k];
}
inline bool merge(int i,int j){
	i=findf(i);
	j=findf(j);
	r[j]=i;
	return i;
}
inline int getone(int n){
	int num=0;
	for(int i=1;i<=n;i++)
		if(r[i]==i)
			num++;
	return num;
}
inline bool eq(int i,int j){
	return findf(i)==findf(j);
}
main(){
	int n;
	cin>>n;
	init(n*3+10);
	int m=0,ans=0,tp_,tp__,type;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>type>>tp_>>tp__;
		if(tp_>n||tp__>n){
			ans++;
			continue;
		}
		if(type==1)
			if(eq(tp_+n,tp__)||eq(tp_+2*n,tp__))
				ans++;
			else
				merge(tp__,tp_),
				merge(tp__+n,tp_+n),
				merge(tp__+2*n,tp_+2*n);
		else if(type==2)
			if(eq(tp_,tp__)||eq(tp_+2*n,tp__))
				ans++;
			else	
				merge(tp_,tp__+2*n),
				merge(tp_+n,tp__),
				merge(tp_+2*n,tp__+n); 
		else
			ans++;
	}
	cout<<ans;
	return 0;
}