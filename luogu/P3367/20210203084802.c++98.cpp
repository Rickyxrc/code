#include<bits/stdc++.h>
using namespace std;
int r[10001];
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
int merge(int i,int j){
	i=findf(i);
	j=findf(j);
	r[j]=i;
	return i;
}
int getone(int n){
	int num=0;
	for(int i=1;i<=n;i++)
		if(r[i]==i)
			num++;
	return num;
}
bool eq(int i,int j){
	return findf(i)==findf(j);
}
int main(){
	int n,m;
	int s,tp_a,tp_b;
	cin>>n>>m;
	init(n);
	for(int i=1;i<=m;i++){
		cin>>s>>tp_a>>tp_b; 
		if(s==1)
			merge(tp_a,tp_b);
		if(s==2)
			if(eq(tp_a,tp_b))
				cout<<"Y"<<endl;
			else
				cout<<"N"<<endl;
	}
	return 0;
}