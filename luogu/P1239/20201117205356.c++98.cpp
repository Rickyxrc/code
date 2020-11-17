#include<iostream>
using namespace std;
int count[15];
void fl(int i){
	while(i){
		count[i%10]++;
		i=i/10;
	}
	return;
}
int main(){
	int a;
	cin>>a;
	if(a>750000000){
		count[1]+=750000000;
		count[1]+=593888896;
		count[1]+=705000000;
		count[1]+=705000000;
		count[1]+=705000000;
		count[1]+=695000001;
		count[1]+=695000000;
		count[1]+=645000001;
		count[1]+=595000000;
		count[1]+=595000000;
	}
	for(int i=(a>100000000)?100000000:1;i<=a;i++){
		fl(i);
	}
	for(int i=0;i<10;i++){
		cout<<count[i]<<endl;
	}
}
/*
--------------------------------
Process exited with return value 0
Press any key to continue . . .
*/