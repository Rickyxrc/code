#include<bits/stdc++.h>
using namespace std;
int r[5001];
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
inline bool eq(int i,int j){
	return findf(i)==findf(j);
}
int main(){
	int n,m,q,tp,tp_;
	cin>>n>>m>>q;
	init(n);
	for(int i=1;i<=m;i++){
		cin>>tp>>tp_;
		merge(tp,tp_);
	}
	for(int i=1;i<=q;i++){
		cin>>tp>>tp_;
		if(eq(tp,tp_))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}