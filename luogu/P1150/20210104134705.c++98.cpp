#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,j=0,i=0;
	cin>>n>>k;
	while(n||j==k){
        if(j>=k){
                j=0;
                n++;
        }
		j++;
		i++;
		n--;
	}
    cout<<i;
}