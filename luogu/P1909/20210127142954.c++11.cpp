#include<bits/stdc++.h>
int main(){
	int n,k1,k2,k3,m1,m2,m3;
	std::cin>>n>>k1>>m1>>k2>>m2>>k3>>m3;
	std::cout<<std::min(int(ceil((double)n/(double)k1)*m1),std::min(int(ceil((double)n/(double)k2)*m2),int(ceil((double)n/(double)k3)*m3)));
}