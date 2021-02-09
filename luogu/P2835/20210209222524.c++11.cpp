#include<bits/stdc++.h>
using namespace std;
int r[201],f[201];
void init(int n){
	for(int i=1;i<=n;i++)
		r[i]=i;
	return;
}
int findf(int k){
	if(r[k]==k)
		return k;
	r[k]=findf(r[k]);
	return r[k];
}
int merge(int i,int j,int tp){
	r[findf(i)]=findf(j);
	f[tp]++;
	return i;
}
int getone(int n){
	int num=0;
	for(int i=1;i<=n;i++)
		if(r[i]==i)
			num++;
		else if(!f[i])
			num++;
	return num;
}
int main(){
	int n,tp;
	cin>>n;
	init(n);
	for(int i=1;i<=n;i++){
		cin>>tp;
		while(tp)
			merge(tp,i,tp),
			cin>>tp;
	}
	cout<<getone(n);
}