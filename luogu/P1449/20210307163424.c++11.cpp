#include<bits/stdc++.h>
using namespace std;
stack<int>k;
int main(){
	string m;
	int Tp=0,Tp_;
	getline(cin,m,'@');
	int l=m.length();
	for(int i=0;i<l;i++){
		if(m[i]=='+'){
			Tp_=k.top();
			k.pop();
			Tp=k.top();
			k.pop();
//			cout<<Tp<<"+"<<Tp_<<"="<<Tp+Tp_<<endl; 
			k.push(Tp+Tp_);
			continue;
		}
		else if(m[i]=='-'){
			Tp_=k.top();
			k.pop();
			Tp=k.top();
			k.pop();
//			cout<<Tp<<"-"<<Tp_<<"="<<Tp-Tp_<<endl; 
			k.push(Tp-Tp_);
			continue;
		}
		else if(m[i]=='*'){
			Tp_=k.top();
			k.pop();
			Tp=k.top();
			k.pop();
//			cout<<Tp<<"*"<<Tp_<<"="<<Tp*Tp_<<endl; 
			k.push(Tp*Tp_);
			continue;
		}
		else if(m[i]=='/'){
			Tp_=k.top();
			k.pop();
			Tp=k.top();
			k.pop();
//			cout<<Tp<<"/"<<Tp_<<"="<<Tp/Tp_<<endl; 
			k.push(Tp/Tp_);
			continue;
		}
		else{
			Tp=0;
			while(m[i]>='0'&&m[i]<='9'){
				Tp=(Tp<<1)+(Tp<<3)+m[i]-48;
				i++;
			}
//			cout<<"in "<<Tp<<endl;
			k.push(Tp);
			continue;
		}
	} 
	cout<<k.top();
	return 0;
}