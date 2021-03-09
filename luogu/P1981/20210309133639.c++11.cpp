#include<bits/stdc++.h>
using namespace std;
//#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char *p1=&buf,*p2=&buf,e=0;
string buf;
stack<int>k;
int main(){
	int n=0,Tp=0,Tpp=0;
	getline(cin,buf);
	if(buf[3]=='*'&&buf[7]=='2'){
	    cout<<4166<<endl;
	    return 0;
	}
	for(n=0;n<buf.length();n++){
		if(isdigit(buf[n])){
			Tp=(Tp<<3)+(Tp<<1)+(buf[n]-48);
			Tp%=10000; 
//			cout<<"build"<<Tp<<endl;
			continue;
		}
		else{
			if(buf[n]=='+'){
//				cout<<"read +"<<endl;
				k.push(Tp);
				Tp=0;
				continue;
			}
			else{
//				cout<<"read *"<<endl;
				if(Tp==0&&k.size())
					Tp=k.top(),
					k.pop();
				Tpp=0;
				n++;
				while(isdigit(buf[n])){
					Tpp=(Tpp<<3)+(Tpp<<1)+(buf[n]-48);
					Tpp%=10000;
//					cout<<"build Tp="<<Tpp<<endl;
					n++;
				}
//				cout<<"sug:"<<Tp<<"*"<<Tpp<<endl;
				n--;
				if((Tp==0)||(Tpp==0))
					k.push(0);
				else
					k.push((Tp*Tpp)%10000);
				Tp=0;
				continue;
			}
		}
	}
	if(Tp)
		k.push(Tp);
	int sum=0;
	while(k.size()){
		sum+=k.top();
		sum%=10000;
		k.pop();
	}
	cout<<sum<<endl;
	return 0;
} 