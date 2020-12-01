#include<bits/stdc++.h>
using namespace std;
int last[100005];
int num=0,n;
bool tc(int i){
	bool flag=0;
		if(last[i]){
			flag=1;
			num++;
			while(last[i]){
				last[i]--;
				i++;
			}
		}
	return flag;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>last[i];
	}
	for(int i=1;i<=n;i++)
		while(tc(i));
	cout<<num;
}