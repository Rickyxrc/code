#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[11],c;
//	scanf("%c-%c%c%c-%c%c%c%c%c-%c",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],a[10]);
	cin>>a[1]>>c>>a[2]>>a[3]>>a[4]>>c>>a[5]>>a[6]>>a[7]>>a[8]>>a[9]>>c>>a[10]; 
	int b[11];
	
	for(int i=1;i<=10;i++){
		b[i]=a[i]-'0';
//		cout<<a[i]<<"|"<<b[i]<<" ";
	}
	if(a[10]=='X')
		b[10]=10;
//	cout<<endl;
	int s=0;
	for(int i=1;i<=9;i++){ 
		s+=b[i]*i;
	}
//	cout<<s%11<<endl;
	if(s%11==b[10])
		cout<<"Right";
	else{
		cout<<b[1]<<"-"<<b[2]<<b[3]<<b[4]<<"-"<<b[5]<<b[6]<<b[7]<<b[8]<<b[9]<<"-";
		if(s%11==10)
			cout<<"X";
		else
			cout<<s%11;
	}
	return 0;
}