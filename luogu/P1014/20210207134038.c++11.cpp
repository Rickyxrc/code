#include<bits/stdc++.h> 
using namespace std;
int main(){
	int fz,fm;
	fz=1,fm=1;
	char type=2;
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
		if(fz==1&&type==2){
			fm++;
			type=1;
			continue;
		}
		else if(fm==1&&type==1){
			fz++;
			type=2;
			continue;
		}
		else if(type==1){
			fm--;
			fz++;
			continue;
		}
		else if(type==2){
			fm++;
			fz--;
			continue;
		}
	cout<<fz<<"/"<<fm;
	return 0;
}