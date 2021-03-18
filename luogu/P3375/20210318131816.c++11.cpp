#include<bits/stdc++.h>
#define maxn 1000001
using namespace std;
int prefix[maxn],mx,n;
char str[maxn],strf[maxn];
void make_prefix(void){
	int len=strlen(str);
	int ind=0;
	prefix[0]=prefix[1]=0;
	for(int i=1;i<len;i++){
		while(ind!=0&&str[i]!=str[ind])
			ind=prefix[ind];
		if(str[i]==str[ind])
			prefix[i+1]=++ind;
		else
			prefix[i+1]=0;
	}
	return;
}
void find(void){
	int ind=0;
	int len=strlen(strf);
	int lenn=strlen(str);
	for(int i=0;i<len;i++){
		while(ind!=0&&strf[i]!=str[ind])
			ind=prefix[ind];
		if(strf[i]==str[ind])
			ind+=1;
		if(ind==lenn)
			cout<<i-lenn+2<<endl;
	}
	return;
}
void print_prefix(void){
//	cout<<"----------"<<endl;
	int len=strlen(str);
	for(int i=1;i<=len;i++){
		cout<<prefix[i]<<" ";
	}
	return;
}
int main(){
	cin>>strf>>str;
	make_prefix();
	find();
	print_prefix();
	return 0;
}