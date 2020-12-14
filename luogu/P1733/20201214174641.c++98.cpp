#include<bits/stdc++.h>
using namespace std;
int main(){
	int l=1;
	int r=1000000000;
	int mid;
	int value;
	mid=(l+r)/2;
	while(1){
		cout<<mid<<endl;
		cin>>value;
		if(value==0)
			return 0;
		if(value==1)
			r=mid-1;
		if(value==-1)
			l=mid+1;
		mid=(l+r)/2;	
	}
}