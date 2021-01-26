#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int y[3];
    cin>>y[0]>>y[1]>>y[2];
    for(int i=0;i<3;i++)
        for(int j=0;j<i;j++)
            if(y[i]>y[j])
                swap(y[i],y[j]);
    cout<<y[2]<<" "<<y[1]<<" "<<y[0];
    return 0;
}