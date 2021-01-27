#include<bits/stdc++.h>
using namespace std;
bool f(int y){
	if(y%4==0){
		if(y%100!=0){
			return 1;
		}
		else{
			if(y%400==0)
				return 1;
			else
				return 0;
		}
	}
	return 0;
}
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	int y,m;
	cin>>y>>m;
	if(m!=2)
		cout<<d[m];
	else
		cout<<(d[2]+f(y));
	return 0;
} 