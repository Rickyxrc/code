#include<bits/stdc++.h>
using namespace std;
int main(){
	char m;
	string a[9];
	int i=1;
	do{
		cin.get(m);
		if(m=='\n')break;
		if(m==':')i++;
		else a[i]+=m;
	}while(m!='\n');
	for(int i=1;i<=8;i++){
		while(a[i][0]=='0')a[i].erase(0,1);
		if(a[i]=="")a[i]="0";
	}
	int zero[9];
	memset(zero,0,sizeof(zero));
	for(int i=1;i<=8;i++)
		if(a[i]=="0")
			zero[i]=zero[i-1]+1;
	int maxx=-1,ind=-1;
	for(int i=1;i<=8;i++)
		if(zero[i]>maxx){
			maxx=zero[i];
			ind=i;
		}
	bool first=1,fst_co=1;
	for(int i=1;i<=8;i++){
		if(i==8&&fst_co){
			cout<<":";
			fst_co=0;
		}
		if((i>ind-maxx)&&(i<=ind)){
			if(first){
				first=false;
				cout<<":";
			}
		}    
		else{
			if(fst_co&&i!=1)
				cout<<":";
			fst_co=0;
			if(i==8)
				cout<<a[i];
			else
				cout<<a[i]<<":";
		}	
	}
	return 0;
}