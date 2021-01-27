#include<bits/stdc++.h>
using namespace std;
int main(){
	int x;
	int w;
	int r=0;
	cin>>x>>w;
	while(w){
		if(w>=7)
			r+=1250,w-=7; 
		else{
			w--;
			if(x!=6&&x!=7)r+=250; 
			x++;
			x%=8;
			if(x==0)
				x=1;
		}
	}
	cout<<r;
}