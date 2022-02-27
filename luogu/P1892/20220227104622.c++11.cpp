#include<bits/stdc++.h>
using namespace std;
int r[10001];
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
inline int merge(int i,int j){
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
int main(){
	int n,m,tp_,tp__;
	char s;
	cin>>n>>m;
	init(n*2);
	for(int i=1;i<=m;i++){
		cin>>s>>tp_>>tp__;
		if(s=='F')
			merge(tp_,tp__);
		else if(s=='E'){
			merge(tp_,tp__+n);
			merge(tp__,tp_+n);
		}
	}
	cout<<getone(n);
	return 0;
}