#include<bits/stdc++.h>
using namespace std;
bool book[10]={0};
void dfs(int n,int step){
	if(step==9){
		if((n/1000000)*2==(n%1000)&&(n/1000000)*3==(n/1000%1000))
			cout<<n/1000000<<" "<<n%1000<<" "<<n/1000%1000<<endl;
		return;
	}
	for(int i=1;i<=9;i++)
		if(book[i]==0){
			book[i]=1;
				dfs((n*10)+i,step+1);
			book[i]=0;
		}
}
int main(){
	dfs(0,0);
	return 0;
}