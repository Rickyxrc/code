#include<iostream>
using namespace std;
int key(char a){
    if(a==' ')
    return (27);
    if(a>='a'&&a<='z')
    return (a-'a'+1);
    return 0;
}
int main(){
    int a[]={0,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4,1};
    string m;
    
    int sum=0;
    getline(cin,m);
    	for(int i=0;i<m.length();i++)
        sum=sum+a[key(m[i])];
    cout<<sum;
    return 0;
} 